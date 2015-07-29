#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

bool prime[(int)2e5 + 100];
vector <int> primes;

void build(int n) {
	memset(prime, true, sizeof prime);

	prime[0] = prime[1] = false;

	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			primes.push_back(i);

			if (i * 1ll * i <= n) {
				for (int j = i * i; j <= n; j += i)
					prime[j] = false;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	build(n);

	for (size_t i = 0; i < primes.size(); i++) {
		if (prime[n - primes[i]]) {
			cout << primes[i] << ' ' << n - primes[i] << endl;
			return 0;
		}
	}

	return 0;
}
