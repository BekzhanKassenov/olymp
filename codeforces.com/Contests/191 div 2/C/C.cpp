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
#define all (x) (x).begin(), (x).end()

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

ll power(ll a, ll st) {
    if (st < 0)
    	return 0;

	if (st == 0)
		return 1;

	if (st & 1) 
		return (power(a, st - 1) * a) % MOD;
	else {
		ll tmp = power(a, st >> 1);
		return (tmp * tmp) % MOD;
	}
}

const ll cnst = (int)1e13;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	getline(cin, s);

	int k;

	cin >> k;

	ll ans = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '0' || s[i] == '5') {
			ans += power(2ll, i);
			ans %= MOD;
		}
	}

	ans %= MOD;

	ll a = power(2, s.size());

	ll tmp = power(a, k);

	tmp = (tmp - 1 + MOD) % MOD;

	tmp = (tmp * power(a - 1, MOD - 2)) % MOD;

	ans *= tmp;

	ans %= MOD;

	cout << ans;

	return 0;
}
