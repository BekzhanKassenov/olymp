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
const int MAXN = 33;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T, n, m;
int w[MAXN];
int prereq[MAXN];
map <string, int> num;
char buf[510];
int dp[1 << 18];
bool calced[1 << 18];

int solve(int mask) {
    if (mask == 0 || calced[mask]) {
        return dp[mask];
    }

    calced[mask] = true;
    int &ans = dp[mask];
    ans = 0;
    int inv = ((1 << n) - 1) ^ mask;
    int day = __builtin_popcount(inv) + 1;

    for (int i = 0; i < n; i++) {
        int shift = 1 << i;
        if ((mask & shift) && (prereq[i] & inv) == prereq[i]) {
            ans = max(ans, day * w[i] + solve(mask ^ shift));
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d\n", &n, &m);
        
        memset(calced, false, sizeof(bool) * (1 << n));
        num.clear();
        for (int i = 0; i < n; i++) {
            prereq[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            gets(buf);

            int pos = 0;
            while (!isdigit(buf[pos])) {
                pos++;
            }

            sscanf(buf + pos, "%d", &w[i]);
            buf[pos - 1] = '\0';
            
            num[string(buf)] = i;
        }

        for (int i = 0; i < m; i++) {
            gets(buf);

            int pos = 0;
            while (strncmp(buf + pos, " --> ", 5) != 0) {
                pos++;
            }

            buf[pos] = '\0';

            int a = num[string(buf)];
            int b = num[string(buf + pos + 5)];
            
            prereq[b] |= 1 << a;
        }
        
        printf("%d\n", solve((1 << n) - 1));
    }


    return 0;
}
