#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <string>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define INF (int)1e9

char s[100010];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;

	cin >> n >> k;

	scanf("%s", s);

	multiset <pair <pair <int, char>, int> > all;

	vector <set <pair <int, int> > > mn(26);

	all.insert(MP(MP(0, s[0]), 0));

	mn[s[0] - 'A'].insert(MP(0, 0));

	vector <int> dp(n);

	dp[0] = 0;

	for (int i = 1; i < n; i++) {
		int ans = INF;

		if (!mn[s[i] - 'A'].empty()) {
			ans = min(ans, (mn[s[i] - 'A'].begin() -> F));
		}

		if (all.begin() -> F.S != s[i])
			ans = min(ans, all.begin() -> F.F + 1);

		dp[i] = ans;

		mn[s[i] - 'A'].insert(MP(dp[i], i));
		all.insert(MP(MP(dp[i], s[i]), i));

		if (i >= k) {
			all.erase(MP(MP(dp[i - k], s[i - k]), i - k));
			mn[s[i - k] - 'A'].erase(MP(dp[i - k], i - k));
		}

		//cerr << dp[i] << ' ';
	}

	cout << dp[n - 1];

	return 0;
}
