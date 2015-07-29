#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = (int)1e6;

bool prime[N];
int primes[(int)1e5];
int cnt[(int)1e5];
int sz;

void build() {
	memset(prime, 1, sizeof prime);

 	prime[0] = prime[1] = false;

	for (int i = 2; i < N; i++) {
		if (prime[i]) {
		 	primes[sz++] = i;

		 	if (i * 1ll * i < N)
		 		for (int j = i * i; j < N; j += i)
		 			prime[j] = false;
		}
	}	
}

int main() {
	freopen("divisors2.in", "r", stdin);
	freopen("divisors2.out", "w", stdout);

	build();

	ll n;

	cin >> n;

	ll cur = 1;

	cin >> n;

	while (true) {
		if (cur * primes[0] > n)
			break;

		for (int i = 0; i < sz; i++) {
		 	if (cur * primes[i] > n)
		 		break;
		 	cur *= primes[i];
		 	cnt[i]++;
		}	
	}

	ll ans1 = 1, ans2 = 1;

	for (int i = 0; i < sz; i++) {
		ans2 *= (cnt[i] + 1);
		for (; cnt[i]; cnt[i]--)
			ans1 *= primes[i];
	}

	cout << ans2 << ' ' << ans1;
}
