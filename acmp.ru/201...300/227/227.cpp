#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int sign(int a) {
	if (a < 0)
		return -1;

	if (a > 0)
		return 1;

	return 0;	
}

const int INF = (int)1e9;

map <int, int> dp;

int rec(int a, int n) {

	int ans = INF;
	if (n == a)
		return 0;

	if (dp.find(n) != dp.end())
		return dp[n];

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans = min(ans, rec(a, n / i) + i);	
		}
	}

	if (n % a == 0) {
		ans = min(ans, n / a);
	}

	dp[n] = ans;

	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x, y;

	cin >> x >> y;

	if (x == y) {
		cout << 0;
		return 0;
	}

	if (x == 0 || y == 0 || sign(x) != sign(y) || (abs(x) > abs(y)) || y % x != 0) {
		cout << -1;
		return 0;
	}

	x *= sign(x);
	y *= sign(y);

	cout << rec(x, y);

	return 0;

}