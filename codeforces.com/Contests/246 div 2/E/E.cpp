/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m;
char ans[maxn][maxn];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
char st[] = {'B', 'C'};

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(int x, int y, int lenx, int leny) {
    cerr << x << ' ' << y << ' ' << lenx << ' ' << leny << endl;
    if (lenx == 0 || leny == 0 || lenx == leny)
        return;

    if (lenx > leny) {
        while (lenx > leny) {
            x += leny;

            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];

                if (ok(ty, tx) && ans[ty][tx] == st[0]) {
                    swap(st[0], st[1]);
                }
            }

            for (int i = 0; i < leny; i++)
                ans[y + i][x] = st[i % 2];

            x++;
                        
           lenx -= leny + 1;
        }
    } else {
        while (leny > lenx) {
            y += lenx;

            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];

                if (ok(ty, tx) && ans[ty][tx] == st[0]) {
                    swap(st[0], st[1]);
                }
            }


            for (int j = 0; j < lenx; j++)
                ans[y][x + j] = st[j % 2];

            y++;
            leny -= lenx + 1;
        }
    }

    solve(x, y, lenx, leny);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    memset(ans, 'A', sizeof ans);
    solve(0, 0, m, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            putchar(ans[i][j]);

        putchar('\n');
    } 

    return 0;
}
