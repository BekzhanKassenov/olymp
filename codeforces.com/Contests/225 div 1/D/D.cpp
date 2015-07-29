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
const int maxn = 1010;
const int maxsum = 10010;
const ll lim = (int)1e13;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, a[maxn], mem[maxn][5 * maxsum];
int* dp[maxn];
ll ans;

int read_int() {
    char c;

    do {
        c = getc(stdin);
    } while (c < '0' || c > '9');

    int res = 0;

    do {
        res = res * 10 + c - '0';
        c = getc(stdin);
    } while (c >= '0' && c <= '9');

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    n = read_int();

    dp[0] = mem[0] + maxsum;

    for (int i = 1; i <= n; i++) {
        a[i] = read_int();
        dp[i] = mem[i] + 2 * maxsum + (maxsum >> 1);
    }

    dp[0][0] = 1;

    ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int sum = -10000; sum <= 10000; sum++) {
            dp[i][sum] += (dp[i - 1][sum + a[i]] + dp[i - 1][sum - a[i]]) % MOD;
        }
        ans += dp[i][0];
        dp[i][0]++;
    }

    printf("%I64d", ans % MOD);

    return 0;
}
