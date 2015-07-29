#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(all(a));

	int x;

	int ans = 0;

	for (int i = 0; i < m; i++) {
		cin >> x;
		ans += *lower_bound(all(a), x) - x;
	}

	cout << ans;

	return 0;
}
