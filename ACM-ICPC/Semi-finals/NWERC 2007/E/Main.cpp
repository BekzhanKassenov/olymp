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
const int MAXSIDE = 1010;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, x[MAXN], y[MAXN];
int dist[MAXSIDE][MAXSIDE];
int ans[MAXSIDE][MAXSIDE];
int XX, YY;

bool ok(int xx, int yy) {
    return 0 <= xx && xx < XX &&
           0 <= yy && yy < YY;
}

void bfs1() {
    queue <int> X, Y;

    for (int i = 0; i < XX; i++) {
        for (int j = 0; j < YY; j++) {
            dist[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        X.push(x[i]);
        Y.push(y[i]);
        dist[x[i]][y[i]] = 0;
    }

    while (!X.empty()) {
        assert(!Y.empty());

        int xx = X.front();
        int yy = Y.front();

        X.pop();
        Y.pop();

        for (int k = 0; k < 4; k++) {
            int tx = xx + dx[k];
            int ty = yy + dy[k];

            if (ok(tx, ty) && dist[tx][ty] == -1) {
                dist[tx][ty] = dist[xx][yy] + 1;
                X.push(tx);
                Y.push(ty);
            }
        }
    }
}

int bfs2(int xs, int ys, int xf, int yf, int check) {
    queue <int> X, Y;

    for (int i = 0; i < XX; i++) {
        for (int j = 0; j < YY; j++) {
            ans[i][j] = -1;
        }
    }

    X.push(xs);
    Y.push(ys);
    ans[xs][ys] = 0;

    if (dist[xs][ys] < check) {
        return -1;
    }

    while (!X.empty()) {
        assert(!Y.empty());

        int xx = X.front();
        int yy = Y.front();

        X.pop();
        Y.pop();

        for (int k = 0; k < 4; k++) {
            int tx = xx + dx[k];
            int ty = yy + dy[k];

            if (ok(tx, ty) && ans[tx][ty] == -1 && dist[tx][ty] >= check) {
                ans[tx][ty] = ans[xx][yy] + 1;
                X.push(tx);
                Y.push(ty);
            }
        }
    }

    return ans[xf][yf];
}   

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d", &n, &XX, &YY);

        int xs, ys, xf, yf;
        scanf("%d%d%d%d", &xs, &ys, &xf, &yf);

        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }

        bfs1();

        int l = 0, r = INF / 2;

        int anssep = 0, anslen = INF;

        while (l <= r) {
            int mid = (l + r) / 2;

            int d = bfs2(xs, ys, xf, yf, mid);
            if (d != -1) {
                anslen = d;
                anssep = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }  
        }

        printf("%d %d\n", anssep, anslen);
    }
    
    return 0;
}
