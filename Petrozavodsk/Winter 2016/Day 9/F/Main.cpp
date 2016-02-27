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
const int MAXN = 510;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN], b[MAXN];
int dp[2][MAXN][MAXN];

bool ok(int i, int j, int k, int l) {
    return (b[i] - b[j]) * (a[k] - a[l]) > 0;
}

void upd(int & a, int b) {
    if(a < b) a =b;
}


int st[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    {
        int l = 1;
        int r = n;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == l) {
                st[i] = 1;
                l++;
            }
            else {
                st[i] = 2;
                r--;
            }
        }
        st[n] = 3;
    }


    for(int i = 1; i <= m; ++i) {
        scanf("%d", b + i);
    }
    
    dp[0][0][0] = m + 1;

    for(int i = 0; i < m; ++i) {
        int id = (i & 1);
        for(int  j = 0; j < n; ++j) {
            for (int low = 0; low <= m; ++ low) {
                int high = dp[id][j][low];

                upd(dp[id ^ 1][j][low], high);

                if(high <= low || b[i + 1] <= low || b[i + 1] >= high) continue;

                if(st[j + 1] == 1 || st[j + 1] == 3) {
                    upd(dp[id ^ 1][j + 1][b[i + 1]], high);                                         
                }
                if(st[j + 1] == 2 || st[j + 1] == 3) {
                    upd(dp[id ^ 1][j + 1][low], b[i + 1]);
                } 
            }
        }
        if(i != m - 1) {
            for(int j = 0; j <= n; ++j) {
                for(int low = 0; low <= m; ++low) {
                    dp[id][j][low] = 0;
                }
            }
        } 
    }
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j <= m; ++j) {
            if(dp[i][n][j] > j) {
                puts("Yes");
                return 0;
            }
        } 
    }
    puts("No");        
    return 0;
}
