#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 1300;

int n;
int x[MAXN], y[MAXN];
int color[MAXN];
double dist[MAXN][MAXN];

double sqr(int n) {
    return n * n;
}

double get_dist(int a, int b) {
    return sqrt(sqr(x[a] - x[b]) + sqr(y[a] - y[b]));
}

bool dfs(int v, double rad, int col) {
    color[v] = col;
    col = 3 - col;

    bool res = true;

    for (int i = 1; i <= n && res; i++) {
        if (dist[v][i] < 2 * rad && i != v) {
            if (!color[i])
                res &= dfs(i, rad, col);
            else if (color[i] == color[v]) {
                res = false;
            }
        }
    }

    return res;
}

bool check(double rad) {
    memset(color, 0, sizeof color);

    for (int i = 1; i <= n; i++)
        if (!color[i] && !dfs(i, rad, 1)) {
            return false;
        }

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = get_dist(i, j);
    
    double l = 0, r = 20000;

    for (int i = 0; i < 50; i++) {    
        double mid = (l + r) / 2;

        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    check(l);
    printf("%.14lf\n", l);

    for (int i = 1; i <= n; i++)
        printf("%d ", color[i]);

    puts("");

    return 0;
}
