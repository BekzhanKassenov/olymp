#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int dp[150][150], n, k;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;

	cin >> n >> k;

	dp[50][0] = 1;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= 50 + n; j++) {
			if (j > 0)
				dp[j][i] += dp[j - 1][i - 1];

			if (j < 149 && j + 1 != n + 50)
				dp[j][i] += dp[j + 1][i - 1];
		}

	}

	cout << dp[50 + n][k];

	return 0;
}
