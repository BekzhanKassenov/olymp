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
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <pair <int, int> > edge[MAXN];
int n, m, a, b, c;
int dp[MAXN], buf[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edge[c].emplace_back(a, b);
    }

    for (int i = 1; i <= 100000; i++) {
        for (auto& e: edge[i]) {
            buf[e.second] = dp[e.second];
        }

        for (auto& e: edge[i]) {
            buf[e.second] = max(buf[e.second], dp[e.first] + 1);
        }

        for (auto& e: edge[i]) {
            dp[e.second] = buf[e.second];
        }
    }


    printf("%d\n", *max_element(dp + 1, dp + 1 + n));
    
    return 0;
}
