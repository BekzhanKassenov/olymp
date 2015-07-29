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
#define MOD (1000 * 1000 * 1000 + 9)
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

ll bin_pow(ll n, ll st) {
	if (st == 0)
		return 1ll;

	if (st & 1)
		return (bin_pow(n, st - 1) * n) % MOD;

   	ll b = bin_pow(n, st >> 1);

   	return (b * b) % MOD;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, k, m;

	cin >> n >> m >> k;

	int cnt = n / k;

	int cntz = n - m;

	ll ans = 0;

	if (cntz < cnt) {
		int c = cnt - cntz;

		m -= c * k;

		ans = (bin_pow(2ll, c + 1) - 2 + MOD) % MOD;

		ans += m;

		ans %= MOD;

		cout << ans;

		return 0;
	}

	cout << m % MOD;

	return 0;
}
