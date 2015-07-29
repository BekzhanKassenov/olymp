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
#define File ""

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

ll dp[100][100];
bool calced[100][100];

ll calc(int cnt, int len) {
    if (cnt == 0)
        return 1;

    if (calced[cnt][len])
        return dp[cnt][len];

    calced[cnt][len] = true;    

    ll& res = dp[cnt][len];

    for (int i = 1; i <= cnt; i += 2) {
        res += calc(cnt - i, len + 1);
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n;

    cin >> n;

    cout << calc(n, 0) << endl;

    return 0;
}
