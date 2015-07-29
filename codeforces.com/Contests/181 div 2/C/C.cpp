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
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define MOD (1000 * 1000 * 1000 + 7)

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> 
T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
T sqr(T n) {
	return (n * n);
}

template <typename T>
T max(T a, T b) {
	return (a > b ? a : b);
}

template <typename T>
T min(T a, T b) {
	return (a < b ? a : b);
}

ll pow_mod(ll a, ll st) {
	if (st == 0)
		return 1;

	if (st & 1) 
	 	return (a * pow_mod(a, st - 1)) % MOD;

	ll b = pow_mod(a, st >> 1);

	return (b * b) % MOD;
}

int a, b, n;

bool good(int m) {

	while (m) {
		int k = m % 10;
		m /= 10;

		if (k != a && k != b)
			return false;
	}
	return true;
}

ll fact[(int)2e6];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> a >> b >> n;

	fact[0] = 1;
	fact[1] = 1;

	for (ll i = 2; i <= n; i++)
		fact[i] = (fact[i - 1] * i) % MOD;

	ll ans = 0;

	for (int i = 0; i <= n; i++) {
		int sum = i * a + (n - i) * b;

		if (good(sum)) { 
			ans += ((fact[n] * pow_mod(fact[i], MOD - 2)) % MOD) * pow_mod(fact[n - i], MOD - 2) % MOD;
			ans %= MOD;
		}	
	}

	cout << ans;
	
	return 0;
}
