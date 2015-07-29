#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll MOD = 9973;
const int predperiod = 8985;
const int period = 9973;

int used[MOD][MOD];

ll my_pow(ll n, int st) {
 	ll res = 1;

 	for (int i = 0; i < st; i++) {
 		res *= n;
 		res %= MOD;
 	}

 	return res;
}

ll g(ll x, ll y) {
	return ((y - 1 + MOD) * my_pow(x, 5) + my_pow(x, 3) - x * y + 3 * x + 7 * y + MOD * MOD * MOD) % MOD; 
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	int k;

	cin >> k;

	if (k >= predperiod) {
		k = (k - predperiod) % period + predperiod;
	}

	ll f = 0;

	for (int i = 1; ;i++) {
		f = g(i % MOD, f);

		//cout << f << ' ' << i << endl;

		if (used[f][i % MOD]) {
			cout << "pre " << used[f][i % MOD] << " per " << i - used[f][i % MOD] << endl;
			return 0;
		}

		if (i > (int)1e8) {
			cout << "ERROR";
			return 1;
		}

		used[f][i % MOD] = i;
	}

	cout << f << endl;

	return 0;
}
