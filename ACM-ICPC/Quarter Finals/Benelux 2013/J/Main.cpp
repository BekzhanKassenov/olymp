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
const int MAXN = 110;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, m;
char s[MAXN][MAXN];
int i1, j1;
int i2, j2;
int dist[MAXN][MAXN];


bool ok(int i, int j) {
    return 0 <= i && i < n &&
           0 <= j && j < m &&
           s[i][j] != '*';
}

void bfs(int si, int sj) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = INF;
        }
    }

    dist[si][sj] = 0;

    queue <int> I, J;
    I.push(si);
    J.push(sj);

    while (!I.empty()) {
        assert(!J.empty());

        int ii = I.front();
        int jj = J.front();

        I.pop();
        J.pop();

        for (int k = 0; k < 4; k++) {
            int ti = ii + di[k];
            int tj = jj + dj[k];

            if (ok(ti, tj)) {
                int cost = 0;
                if (s[ti][tj] == '#') {
                    cost = 1;
                }

                if (dist[ti][tj] > dist[ii][jj] + cost) {
                    dist[ti][tj] = dist[ii][jj] + cost;
                    I.push(ti);
                    J.push(tj);
                }
            }
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);
    
    while (T--) {
        scanf("%d%d\n", &n, &m);

        for (int i = 0; i < n; i++) {
            gets(s[i]);
        }

        i1 = j1 = i2 = j2 = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '$') {
                    if (i1 == -1) {
                        i1 = i, j1 = j;
                    } else {
                        i2 = i, j2 = j;
                    }
                }
            }
        }

        int val1 = 0;
        int ans = INF;
        bfs(i1, j1);

        int mindist = INF;
        for (int i = 0; i < n; i++) {
            if (s[i][0] != '*') {
                mindist = min(mindist, dist[i][0]);
            }

            if (s[i][m - 1] != '*') {
                mindist = min(mindist, dist[i][0]);
            }
        }

        for (int i = 0; i < m; i++) {
            if (s[0][i] != '*') {
                mindist = min(mindist, dist[0][i]);
            }

            if (s[n - 1][i] != '*') {
                mindist = min(mindist, dist[n - 1][i]);
            }
        }

        val1 = mindist;
        ans = min(ans, mindist + dist[i2][j2]);

        bfs(i2, j2);
        mindist = INF;
        for (int i = 0; i < n; i++) {
            if (s[i][0] != '*') {
                mindist = min(mindist, dist[i][0]);
            }

            if (s[i][m - 1] != '*') {
                mindist = min(mindist, dist[i][0]);
            }
        }

        for (int i = 0; i < m; i++) {
            if (s[0][i] != '*') {
                mindist = min(mindist, dist[0][i]);
            }

            if (s[n - 1][i] != '*') {
                mindist = min(mindist, dist[n - 1][i]);
            }
        }

        ans = min(ans, mindist + dist[i1][j1]);
        val1 += mindist;
        ans = min(ans, val1);

        printf("%d\n", ans);

    }
    return 0;
}
