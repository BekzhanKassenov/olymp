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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, m, ans, ans2, ans3;
int power2[MAXN][MAXN], power3[MAXN][MAXN];

void dfs(int row, int col, int p2, int p3) {
    p2 += power2[row][col];
    p3 += power3[row][col];

    if (row < n - 1) {
        dfs(row + 1, col, p2, p3);
    }

    if (col < m - 1) {
        dfs(row, col + 1, p2, p3);
    }

    if (row == n - 1 && col == m - 1 && min(p2, p3) > ans) {
        ans = min(p2, p3);
        ans2 = p2, ans3 = p3;
    }
}   

void clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            power2[i][j] = 0;
            power3[i][j] = 0;
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d%d", &n, &m);
        clear();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                scanf("%d", &x);

                while (x % 2 == 0) {
                    power2[i][j]++;
                    x /= 2;
                }

                while (x % 3 == 0) {
                    power3[i][j]++;
                    x /= 3;
                }
            }
        }

        ans = ans2 = ans3 = 0;
        dfs(0, 0, 0, 0);

        printf("%d\n", ans);
    }
                
    return 0;
}
