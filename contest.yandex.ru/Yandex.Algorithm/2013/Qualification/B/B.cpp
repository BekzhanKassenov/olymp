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
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> 
inline T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n;

bool prime[100010];

vector <int> primes;
int sz;

void build() {
	memset(prime, true, sizeof prime);

	prime[0] = prime[1] = false;

	for (int i = 2; i < 100010; i++) {
		if (prime[i]) {
			primes.push_back(i);

			if (i * 1ll * i < 100010) {
				for (int j = i * i; j < 100010; j += i)
					prime[j] = false;
			}
		}
	}

	sz = primes.size();
}

bool check(long long n) {
	int cnt = 0;

	for (int i = 0; i < sz; i++) {
		while (n % primes[i] == 0) {
			n /= primes[i];
			cnt++;
		}

		if (n == 1)
			break;
	}

	if (n > 1) 
		cnt++;

	return (cnt == 2);
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	build();
	
	for (int i = 2; i <= n; i++) {
		if (check(i * 1ll * i - 1))
			printf("%d\n", i);
	}

	return 0;
}
