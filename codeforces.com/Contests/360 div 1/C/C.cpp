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
const int MAXN = 510;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int c[MAXN];
bool dp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            for (int l = k; l >= 0; l--) {
                if (dp[j][l] && j + c[i] < MAXN) {
                    dp[j + c[i]][l] = true;

                    if (l + c[i] < MAXN) {
                        dp[j + c[i]][l + c[i]] = true;
                    }
                }
            }
        }
    }

    vector <int> ans;
    for (int i = 0; i <= k; i++) {
        if (dp[k][i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int x: ans) {
        printf("%d ", x);
    }   

    puts("");

    return 0;
}
