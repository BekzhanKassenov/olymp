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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN];
double dp[MAXN];
int sum[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s + 1);
    n = strlen(s + 1);
    dp[1] = 1;

    for (int i = 1; i < n; i++) {
        for (int pos = 0; pos <= i; pos++) {
            int pos = i - k + 1;
            int val = sum[i] - sum[pos - 1];
            if (s[pos] == 'C') {
                ans += val;
            } else {
                ans += k - val;
            }
        }
    }
    
    return 0;
}
