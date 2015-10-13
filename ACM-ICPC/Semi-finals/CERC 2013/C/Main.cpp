/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
const int LG = 17;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T, n;
int level[MAXN];
long long a[MAXN];
long long table[LG][MAXN];

long long gcd(long long a, long long b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

long long get_gcd(int l, int r) {
    int lev = level[r - l];

    return gcd(table[lev][l], table[lev][r - (1 << lev)]);
}

long long solve(int pos) {
    long long g = a[pos];

    int base = pos;

    long long result = 0;
    while (base < n) {
        int l = base + 1, r = n;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (get_gcd(pos, mid) == g) {
                l = mid + 1;
                base = mid;
            } else {
                r = mid - 1;
            }   
        }

        result = max(result, (base - pos) * g);
        g = get_gcd(pos, base + 1);
    }   

    return result;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    level[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        level[i] = level[i >> 1] + 1;
    }

    while (T--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%I64d\n", &a[i]);
            table[0][i] = a[i];
        }

        if (n == 1) {
            printf("%I64d\n", a[0]);
            continue;
        }

        for (int lev = 1; lev < LG; lev++) {
            for (int i = 0; i < n; i++) {
                table[lev][i] = table[lev - 1][i];

                if (i + (1 << lev) <= n) {
                    table[lev][i] = gcd(table[lev - 1][i], table[lev - 1][i + (1 << (lev - 1))]);
                }
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i));
        }

        printf("%I64d\n", ans);
    }
    
    return 0;
}
