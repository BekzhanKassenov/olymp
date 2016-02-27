/****************************************
**          Solution by NU #1          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1e18;
const int MAXN = 4010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN], p[MAXN];
int minopt[MAXN][MAXN], maxopt[MAXN][MAXN];
long long ans[MAXN];
long long dp[MAXN][MAXN];
vector <int> children[MAXN];

vector <int> seq;
int len;
long long S[MAXN];

void dfs(int v) {
    seq.push_back(a[v]);
    len++;
    S[len] = S[len - 1] + a[v];

    dp[len][len] = a[v];
    minopt[len][len] = maxopt[len][len] = len;
    
    for (int l = 2; l <= len; l++) {
        int rr = len;
        int ll = rr - l + 1;

        dp[ll][rr] = INF;
        for (int k = maxopt[ll][rr - 1]; k <= min(minopt[ll + 1][rr], rr - 1); k++) {
            long long ndp = dp[ll][k] + dp[k + 1][rr];

            if (dp[ll][rr] > ndp) {
                dp[ll][rr] = ndp;
                minopt[ll][rr] = k;
                maxopt[ll][rr] = k;
            } else if (dp[ll][rr] == ndp) {
                maxopt[ll][rr] = k;
            }  
        }

        dp[ll][rr] += S[rr] - S[ll - 1];
    }

    ans[v] = dp[1][len];
    
    for (int to: children[v]) {
        dfs(to);
    }

    len--;
    seq.pop_back();
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
        children[p[i]].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        printf(I64 "\n", ans[i]);
    }
    
    return 0;
}
