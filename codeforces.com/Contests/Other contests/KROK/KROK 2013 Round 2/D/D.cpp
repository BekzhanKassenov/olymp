/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define MOD (1000 * 1000 * 1000 + 7)

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> 
T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
T sqr(T n) {
	return (n * n);
}

template <typename T>
T max(T a, T b) {
	return (a > b ? a : b);
}

template <typename T>
T min(T a, T b) {
	return (a < b ? a : b);
}

int a[100][100], dp[100][100], cnt, n, m, k;

bool used[100];

void init() {
	memset(used, 0, sizeof used);

	cnt = k;

	if (a[0][0] != 0) {
		used[a[0][0]] = true;
		cnt--;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	cin >> n >> m >> k;

	if (n + m - 1 > k) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	if (a[0][0] == 0)
		dp[0][0] = k;
	else 
		dp[0][0] = 1;

	init();

	for (int i = 1; i < n; i++) {
		if (a[i][0] == 0) {
			dp[i][0] = (dp[i - 1][0] * cnt) % MOD;
		} else {
			if (!used[a[i][0]])
				cnt--;

			used[a[i][0]] = true;

			dp[i][0] = dp[i - 1][0];
		}
	}

	init();

	for (int i = 1; i < m; i++) {
		if (a[0][i] == 0) {
			dp[0][i] = (dp[0][i - 1] * cnt) % MOD;
		} else {
			if (!used[a[0][i]])
				cnt--;

			used[a[0][i]] = true;

			dp[0][i] = dp[0][i - 1];	
		}
	}

	init();

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (a[i][j] == 0) {
				dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) * 1ll * cnt) % MOD;
			} else {
				if (!used[a[i][j]])
					cnt--;
				used[a[i][j]] = true;

				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}
		}
	}

	cout << dp[n - 1][m - 1];


	return 0;
}
