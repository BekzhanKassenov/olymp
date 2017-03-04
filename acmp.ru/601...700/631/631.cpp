#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 100010;

int dp[MAXN];


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 2;

    vector <int> points{1, 2};

    for (int i = 3; i <= n; i++) {
        auto f = [i](int v) {
            return 1 + max(dp[v] + 1, dp[i - v]);
        };

        dp[i] = 1e9;
        for (int v : points) {
            dp[i] = min(dp[i], f(v));
            dp[i] = min(dp[i], f(i - v));
        }

        if (dp[i] != dp[i - 1]) {
            points.push_back(i - 1);
            points.push_back(i);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
