/****************************************
**          Solution by NU #2          **
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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

const int maxn = 1010;
int a[maxn][maxn];
int n, m, mn = INF;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
bool used[maxn][maxn];

bool ok(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool check(int _time) {
    queue <int> x, y;
    
    memset(used, 0, sizeof used);
    
    for (int j = 0; j < m; j++) {
        if (a[0][j] < _time) {
            x.push(0);
            y.push(j);
            used[0][j] = true;
        }
    }
    
    while (!x.empty()) {
        int xx = x.front();
        int yy = y.front();
        x.pop();
        y.pop();
        
        for (int i = 0; i < 4; i++) {
            int tx = xx + dx[i];
            int ty = yy + dy[i];
            
            if (ok(tx, ty) && !used[tx][ty] && a[tx][ty] < _time) {
                x.push(tx);
                y.push(ty);
                used[tx][ty] = true;
            }
        }
    }
    
    for (int j = 0; j < m; j++)
        if (used[n - 1][j])
            return true;
            
    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            cin >> a[i][j];
            mn = min(mn, a[i][j]);
        }
    } 
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] -= mn;
            
    int l = 0, r = INF;
    
    while (r - l > 5) {
        int mid = (l + r) >> 1;
        
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    
    for (int i = l; i <= r; i++) {
        if (check(i)) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
r