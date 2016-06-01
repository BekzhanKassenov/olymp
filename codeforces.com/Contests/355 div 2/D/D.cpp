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
const int MAXN = 310;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, p;
int a[MAXN][MAXN];
vector <int> pos[MAXN];
vector <pair <int, int> > nums[MAXN * MAXN];
int dist[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &p);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);

            nums[a[i][j]].emplace_back(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                pos[i].push_back(j);
                dist[i][j] = i + j;
            }
        }
    }

    for (int num = 2; num <= p; num++) {
        for (const auto& it: nums[num]) {
            int& ans = dist[it.first][it.second];
            ans = INF;

            for (int i = 0; i < n; i++) {
                auto l = upper_bound(all(pos[i]), it.second);

                if (l != pos[i].begin()) {
                    l--;

                    ans = min(ans, dist[i][*l] + abs(i - it.first) + abs(*l - it.second));
                }

                auto r = lower_bound(all(pos[i]), it.second);
                if (r != pos[i].end()) {
                    ans = min(ans, dist[i][*r] + abs(i - it.first) + abs(*r - it.second));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            pos[i].clear();
        }

        for (const auto& it: nums[num]) {
            pos[it.first].push_back(it.second);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == p) {
                printf("%d\n", dist[i][j]);
                return 0;
            }
        }
    }
    
    return 0;
}
