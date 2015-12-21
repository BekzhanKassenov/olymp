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
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char s[MAXN][MAXN];
int c[2];
int dist[MAXN][MAXN];

bool ok(int x, int y) {
    return 0 <= x && x < n &&
           0 <= y && y < m;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &m, &n);
    scanf("%d%d\n", &c[0], &c[1]);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = INF;
        }
    }

    queue <int> I, J;
    I.push(0);
    J.push(0);
    dist[0][0] = 0;

    while (!I.empty()) {
        assert(!J.empty());

        int ii = I.front();
        int jj = J.front();

        I.pop();
        J.pop();

        for (int k = 0; k < 4; k++) {
            int ti = ii + di[k];
            int tj = jj + dj[k];

            if (ok(ti, tj) && s[ti][tj] != '#' && dist[ti][tj] > dist[ii][jj] + c[(ti + tj) % 2]) {
                dist[ti][tj] = dist[ii][jj] + c[(ti + tj) % 2];
                I.push(ti);
                J.push(tj);
            }
        }
    }

    if (dist[n - 1][m - 1] == INF) {
        puts("IMPOSSIBLE");
    } else {
        printf("%d\n", dist[n - 1][m - 1]);
    }

    return 0;
}
