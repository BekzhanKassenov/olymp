#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

#define sqr(x) (x) * (x)
#define ll long long

bool fired(ll y, ll x, ll r) {
	if (sqr(x) + sqr(y) < sqr(r))
		return true;
	
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ll rs;

	cin >> rs;

	long long ans = 0;

	for (ll i = rs - 1; i >= 0; i--) {
		ll l = 0, r = rs + 1;

		ll tmp = 0;

		while (r - l > 5) {
			ll m = l + ((r - l) >> 1);

			if (!fired(i, m, rs))
				r = m;
			else 
				l = m;	
		}

		for (int j = l; j <= r; j++) {
			if (fired(i, j, rs))
				tmp = j + 1;
		}
		ans += tmp;
		//cout << i << ' ' << ans << ' ' << l << ' ' << r << endl;
	}

	cout << ans * 4;
}
