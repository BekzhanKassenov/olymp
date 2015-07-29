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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

map <string, int> num;
int T, n, m;
char s[110];
int engine[110];
int query[1010];
int dp[110][1010];
bool calced[110][1010];
int last[110][1010];

int go(int i, int j) {
    if (calced[i][j])
        return dp[i][j];

    calced[i][j] = true;
    int& ans = dp[i][j];
    j = last[i][j];
    ans = 0;

    if (j < m) {
        int temp = INF;
        for (int k = 0; k < n; k++) {
            if (k != i)
                temp = min(temp, go(k, j));
        }

        ans += temp + 1; 
    }               

    return ans; 
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        num.clear();
        scanf("%d\n", &n);

        for (int i = 0; i < n; i++) {
            gets(s);
            string temp(s);

            if (!num.count(temp)) {
                int size = num.size();
                num[temp] = size;
            }
            
            engine[i] = num[temp];
        }

        scanf("%d\n", &m);

        for (int i = 0; i < m; i++) {
            gets(s);
            string temp(s);

            if (!num.count(temp)) {
                int size = num.size();
                num[temp] = size;
            }
            
            query[i] = num[temp];
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= m; j++) {
                calced[i][j] = false;
                last[i][j] = m;
            }

        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if (engine[i] == query[j])
                    last[i][j] = j;
                else
                    last[i][j] = last[i][j + 1];
            }
        }   

        int ans = INF;

        for (int i = 0; i < n; i++) {
            ans = min(ans, go(i, 0));
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
