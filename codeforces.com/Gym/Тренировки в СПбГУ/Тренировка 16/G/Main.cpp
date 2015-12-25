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
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a, b, c;
int grundy[MAXN];
bool used[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &a, &b, &c);

    grundy[1] = 0;

    for (int i = 2; i <= max(max(a, b), c); i++) {
        memset(used, false, sizeof (used));

        for (int j = 1; j < i; j++) {
            int to = max(j, i - j);
            used[grundy[to]] = true;
        }

        for (int j = 0; ; j++) {
            if (!used[j]) {
                grundy[i] = j;
                break;
            }
        }
    }

    int res = grundy[a] ^ grundy[b] ^ grundy[c];

    if (res == 0) {
        puts("NO");
        return 0;
    }

    bool found = false;
    int ansa = -1, ansb = -1, ansc = -1;

    for (int i = 1; i < a && !found; i++) {
        if ((grundy[i] ^ grundy[b] ^ grundy[c]) == 0 && (a - i) <= i) {
            ansa = i;
            ansb = b;
            ansc = c;
        }
    }

    for (int i = 1; i < b && !found; i++) {
        if ((grundy[a] ^ grundy[i] ^ grundy[c]) == 0 && (b - i) <= i) {
            ansa = a;
            ansb = i;
            ansc = c;
        }
    }

    for (int i = 1; i < c && !found; i++) {
        if ((grundy[a] ^ grundy[b] ^ grundy[i]) == 0 && (c - i) <= i) {
            ansa = a;
            ansb = b;
            ansc = i;
        }
    }
    
    puts("YES");
    printf("%d %d %d\n", ansa, ansb, ansc);

    return 0;
}
                                                                        