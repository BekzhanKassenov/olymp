#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 110;
const int INF = (int)1e9;

int dp[maxn][maxn], k[maxn], m[maxn], n;
bool calced[maxn][maxn];

int calc(int l, int r) {
    if (l >= r)
        return 0;

    if (calced[l][r])
        return dp[l][r];

    calced[l][r] = true;

    dp[l][r] = min(calc(l, r - 1), calc(l + 1, r));
    
    for (int i = l + 1; i < r - 1; i++) {
        dp[l][r] = min(dp[l][r], calc(l, i) + calc(i + 1, r));
    }

    dp[l][r] += m[l] * k[r];

    return dp[l][r];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> m[i] >> k[i];

    cout << calc(0, n - 1) << endl;

    return 0;
}
