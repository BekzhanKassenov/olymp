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

ll bin_search(long long c, long long n) {
	ll l = -1, r = n + 1;

	while (r - l > 1) {
		ll m = (l + r) >> 1;

	   	if (m * c + ((m * (m - 1)) >> 1) == n)
	   		return m;

	   	if (m * c + ((m * (m - 1)) >> 1) > n)
	   		r = m;
	   	else
	   		l = m;	
	}
	return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	long long n;

	cin >> n;

	bool flag = false;

	for (int i = 1; i <= 63; i++) {
		long long c = (1ll << i) - 1;

		long long t = bin_search(c, n);
		
		if (t != -1) {
			cout << t << ' ' << i << ' ' << t * (c + 1) << endl;;
			flag = true;
		}
	}

	if (!flag) 
		cout << -1;

	return 0;
}
