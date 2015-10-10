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
const int INF = 500 * 1000 * 1000;
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
int dist1[MAXN][MAXN], dist2[MAXN][MAXN], dist3[MAXN][MAXN];

bool ok(int i, int j) {
    return 0 <= i && i < n &&
           0 <= j && j < m &&
           s[i][j] != '*';
}

void run(int si, int sj, int dist[MAXN][MAXN]) {
    deque <int> I, J;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = INF;
        }
    }

    if (si == -1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && s[i][j] != '*') {
                    I.push_back(i);
                    J.push_back(j);

                    dist[i][j] = s[i][j] == '#';
                }
            }
        }
    } else {
        I.push_back(si);
        J.push_back(sj);
        dist[si][sj] = 0;
    }

    while (!I.empty()) {
        int i = I.front();
        int j = J.front();

        I.pop_front();
        J.pop_front();

        for (int k = 0; k < 4; k++) {
            int ti = i + di[k];
            int tj = j + dj[k];

            if (ok(ti, tj)) {
                int cost = s[ti][tj] == '#';

                if (dist[ti][tj] == INF) {
                    dist[ti][tj] = dist[i][j] + cost;
                    I.push_back(ti);
                    J.push_back(tj);
                } else if (dist[ti][tj] > dist[i][j] + cost) {
                    dist[ti][tj] = dist[i][j] + cost;
                    I.push_front(ti);
                    J.push_front(tj);
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

        run(i1, j1, dist1);
        run(i2, j2, dist2);
        run(-1, -1, dist3);

        int val1 = dist3[i1][j1] + dist1[i2][j2]; // exit -> one -> two
        int val2 = dist3[i2][j2] + dist2[i1][j1]; // exit -> two -> one
        int val3 = dist3[i1][j1] + dist3[i2][j2]; // exit -> one, exit -> two
        int val4 = INF;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diff = 0;
                if (s[i][j] == '#') {
                    diff = 2;
                }

                val4 = min(val4, dist1[i][j] + dist2[i][j] + dist3[i][j] - diff);
            }
        }

        int ans = min(min(val1, val2), min(val3, val4));

        printf("%d\n", ans);
    }
    return 0;
}
