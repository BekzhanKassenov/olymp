/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000 * 1000 * 10 + 2;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

class TheKingsFactorization {
public:
	bitset <MAXN> prime;
	vector <int> primes;
	
    vector <long long> getVector(long long N, vector <long long> primes) {
		vector <long long> result = primes;

		for (size_t i = 0; i < primes.size(); i++) {
		 	 N /= primes[i];
		}

		if (N == 1)
			return result;

		if (primes.size() == 1u) {
			result.push_back(N);
			sort(all(result));
			return result;
		}

		// Sieve 
		for (int i = 0; i < MAXN; i++)
			prime[i] = true;

		prime[0] = prime[1] = false;

		for (int i = 2; i < MAXN; i++) {
			if (prime[i]) {
			 	primes.push_back(i);

			 	if (1ll * i * i < MAXN) {
			 	 	for (int j = i * i; j < MAXN; j += i)
			 	 		prime[j] = false;
			 	}
			}
		}

		// Factorization
		for (size_t i = 0; i < primes.size() && N > 1; i++) {
		 	while (N % primes[i] == 0) {
		 	 	result.push_back(primes[i]);
		 	 	N /= primes[i];
		 	}
		}

		if (N > 1) {
		 	result.push_back(N);
		}

		sort(all(result));

		return result;
    }
};

int main() {
 	vector <long long> temp;
 	temp.push_back(2);
 	temp.push_back(5);

	TheKingsFactorization test;
	vector <long long> res = test.getVector(210, temp);

	for (size_t i = 0; i < res.size(); i++)
		cerr << res[i] << ' ';

	cerr << endl;
}