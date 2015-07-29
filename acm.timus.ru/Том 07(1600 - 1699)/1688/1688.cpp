#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	long long n;

	cin >> n;

	n *= 3;

	size_t cnt = 0;

	int cur, m;
	
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> cur;
		cnt += cur;

		if (cnt > n) {
			cout << "Free after " << i + 1 << " times.";
			return 0;
		}
	}

	cout << "Team.GOV!";
	return 0;
}
