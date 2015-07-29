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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int pawnx[] = { 1, 1};
int pawny[] = {-1, 1};

int dx[] = {1, -1, 0};
int dy[] = {0,  0, 1};

int cas;
int n, m, ans;
char s[MAXN][MAXN];
int a[MAXN][MAXN];
int dist[MAXN][MAXN];

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void make() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 0;
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;

            if (s[i][j] == '1') {
                a[i][j]++;

                for (int k = 0; k < 2; k++) {
                    int ti = i + pawnx[k];
                    int tj = j + pawny[k];

                    if (ok(ti, tj))
                        a[ti][tj]++;
                }
            }
        }
    }
}

void dfs(int x, int y) {
    if (y == m - 1) {
        if (ans == -1 || ans > dist[x][y])
            ans = dist[x][y];
    }

    //cout << x << ' ' << y << ' ' << dist[x][y] << ' ' << endl;

    for (int i = 0; i < 3; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (ok(tx, ty)) {
            if (a[tx][ty] == 0) {
                if (dist[tx][ty] == -1 || dist[tx][ty] > dist[x][y]) {
                    dist[tx][ty] = dist[x][y];
                    dfs(tx, ty);
                } 
            } else if (a[tx][ty] == 1 && s[tx][ty] == '1') {
                if (dist[tx][ty] == -1 || dist[tx][ty] > dist[x][y] + 1) {
                    dist[tx][ty] = dist[x][y] + 1;

                    for (int k = 0; k < 2; k++) {
                        int ttx = tx + pawnx[k];   
                        int tty = ty + pawny[k];   
                                                 
                        if (ok(ttx, tty))          
                            a[ttx][tty]--;         
                    }                            

                    dfs(tx, ty);

                    for (int k = 0; k < 2; k++) {
                        int ttx = tx + pawnx[k];   
                        int tty = ty + pawny[k];   
                                                 
                        if (ok(ttx, tty))          
                            a[ttx][tty]++;         
                    }                            
                }                                                           
            }
        }
    }
}


int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while(scanf("%d%d\n", &n, &m) && (n || m)) {
        ans = -1;
        cas++;
        for (int i = 0; i < n; i++)
            gets(s[i]);

        make();

        dist[n - 1][0] = 0;
        dfs(n - 1, 0);

        printf("Case %d: ", cas);
        if (ans == -1)
            printf("Impossible\n");
        else
            printf("%d\n", ans);
    }
    
    return 0;
}
