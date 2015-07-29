#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	double n, k, m;

	cin >> n >> k >> m;

	m /= 100;

	int ans = 0;

	while (n > k) {
		n -= (n * m);
		ans++;	
	}

	cout << ans;
}
