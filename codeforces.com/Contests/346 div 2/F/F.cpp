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
const int MAXN = 1010;
const int MAXG = MAXN * MAXN * 5;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
long long k;
int a[MAXN][MAXN];
vector <int> g[MAXG];
int size[MAXG], num[MAXG];
bool used[MAXG];

bool ok(int i, int j) {
    return 0 <= i && i < n &&
           0 <= j && j < m;
}

void dfs(int v, int st, int nver) {
    used[v] = true;
    size[nver] += size[v];

    for (int to: g[v]) {
        if (!used[to]) {
            if (num[to] >= num[st]) {
                dfs(to, st, nver);
            } else {
                g[nver].push_back(to);
                g[to].push_back(nver);
            }
        }
    }
}

int ans[MAXN][MAXN];
void dfsAns(int i, int j, int num, int& cnt) {
    if (cnt == 0) {
        return;
    }

    ans[i][j] = num;
    cnt--;

    for (int k = 0; k < 4; k++) {
        int ti = i + di[k];
        int tj = j + dj[k];

        if (ok(ti, tj) && ans[ti][tj] == 0 && a[ti][tj] >= num) {
            dfsAns(ti, tj, num, cnt);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    scanf("%lld", &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    vector <int> divs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (k % a[i][j] == 0 && k / a[i][j] <= n * m) {
                divs.push_back(a[i][j]);
            }
        }
    }

    sort(all(divs));
    divs.resize(unique(all(divs)) - divs.begin());
    reverse(all(divs));

    vector <vector <pair <int, int> > > start(divs.size());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (binary_search(all(divs), a[i][j])) {
                start[lower_bound(all(divs), a[i][j]) - divs.begin()].emplace_back(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            size[i * m + j] = 1;
            num[i * m + j ] = a[i][j];
            for (int k = 0; k < 4; k++) {
                int ti = i + di[k];
                int tj = j + dj[k];

                if (ok(ti, tj)) {
                    g[i * m + j].push_back(ti * m + tj);
                }
            }
        }
    }

    int last = n * m;
    for (size_t i = 0; i < divs.size(); i++) {
        for (const auto& p: start[i]) {
            int ind = p.first * m + p.second;

            if (!used[ind]) {
                num[last] = num[ind];
                dfs(ind, ind, last);

                if (size[last] >= k / divs[i]) {
                    puts("YES");
                    int cnt = k / divs[i];
                    dfsAns(p.first, p.second, a[p.first][p.second], cnt);

                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < m; y++) {
                            printf("%d ", ans[x][y]);
                        }
                        puts("");
                    }
                    return 0;
                }

                last++;
            } 
        }
    }

    puts("NO");

    return 0;
}
