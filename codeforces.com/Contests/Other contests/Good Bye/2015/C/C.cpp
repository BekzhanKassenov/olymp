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

int n, m;
char s[MAXN][MAXN];
int vert[MAXN][MAXN];
int horiz[MAXN][MAXN];

int get(int arr[MAXN][MAXN], int x, int y, int xx, int yy) {
    if (x > xx || y > yy) {
        return 0;
    }
                             /*
    cerr << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
    cerr << arr[xx][yy] << ' ' << arr[x - 1][yy] << ' ' << arr[xx][y - 1] << ' ' << arr[x - 1][y - 1] << endl;
    cerr << endl;
    */

    return arr[xx][yy] - arr[x - 1][yy] - arr[xx][y - 1] + arr[x - 1][y - 1];
}

int query(int x, int y, int xx, int yy) {
    int ans = 0;

    if (x < xx) {
        ans += get(vert, x + 1, y, xx, yy);
    }
        
    if (y < yy) {
        ans += get(horiz, x, y + 1, xx, yy);
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);

    for (int i = 1; i <= n; i++) {
        gets(s[i] + 1);
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vert[i][j] = vert[i - 1][j] + (s[i][j] == '.' && s[i - 1][j] == '.');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vert[i][j] += vert[i][j - 1];
        }
    }

    for (int j = 2; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            horiz[i][j] = horiz[i][j - 1] + (s[i][j] == '.' && s[i][j - 1] == '.');
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            horiz[i][j] += horiz[i - 1][j];
        }
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int x, y, xx, yy;
        scanf("%d%d%d%d", &x, &y, &xx, &yy);

        printf("%d\n", query(x, y, xx, yy));
    }

    return 0;
}
