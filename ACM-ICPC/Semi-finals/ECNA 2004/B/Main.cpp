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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, d;
int ans[MAXN];
bool used[MAXN];
bool prime[MAXN * MAXN];

void build() {
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < MAXN * MAXN; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAXN * MAXN; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool check(int pos) {
    int sum = ans[pos];
    for (int i = pos - 1; i >= 0 && i >= pos - d + 1; i--) {
        sum += ans[i];

        if (prime[sum]) {
            return false;
        }
    }

    return true;
}

bool rec(int pos) {
    if (pos >= m - n + 1) {
        return true;
    }
    
    bool found = false;
    for (int i = n; i <= m && !found; i++) {
        if (!used[i]) {
            ans[pos] = i;

            if (check(pos)) {
                used[i] = true;
                found |= rec(pos + 1);
                used[i] = false;
            }
        }
    }
    
    return found;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    build();
    
    for (scanf("%d%d%d", &n, &m, &d); n > 0 || m > 0 || d > 0; scanf("%d%d%d", &n, &m, &d)) {
        if (rec(0)) {
            printf("%d", ans[0]);
            for (int i = 1; i < m - n + 1; i++) {
                printf(",%d", ans[i]);
            }
            puts("");
        } else {
            puts("No anti-prime sequence exists.");
        }
    }
    
    return 0;
}
