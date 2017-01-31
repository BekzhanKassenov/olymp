/****************************************
**     Solution by Bekzhan Kassenov    **
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
const int MAXN = 60;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char s[MAXN][MAXN];

template <typename Predicate>
int getAns(int pos, Predicate pred) {
    int ansl = -1;
    for (int i = 0; i < n; i++) {
        if (pred(s[pos][i])) {
            ansl = i;
            break;
        }
    }

    int ansr = -1;
    for (int i = m - 1; i >= 0; i--) {
        if (pred(s[pos][i])) {
            ansr = m - i;
            break;
        }
    }

    return min(ansl, ansr);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }

                int ansi = getAns(i, [](char c) { return isdigit(c); });
                int ansj = getAns(j, [](char c) { return islower(c); });
                int ansk = getAns(k, [](char c) { return strchr("#*&", c) != NULL; });

                if (ansi != -1 && ansj != -1 && ansk != -1) {
                    ans = min(ans, ansi + ansj + ansk);
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
