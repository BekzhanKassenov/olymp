/***************************************
**    Solution by Bekzhan Kassenov    **
**    For: NU Open Spring 2013        **
***************************************/
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
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (123456789)
#define ll long long 
#define ull unsigned long long
#define File "passwords"

ll fact(int n) {
	if (n == 0)
		return 1;
	else
		return (n * fact(n - 1)) % MOD;	
}

ll pow_mod(int n, int st) {
	if (st == 0)
		return 1;

	if (st & 1)
		return (n * pow_mod(n, st - 1));
	else {
		ll tmp = pow_mod(n, st >> 1);

		return (tmp * tmp) % MOD;
	}	
}

ll pw(int n) {
	if (n == 1 || n == 2)
		return n;

	return pow_mod(2, n - 2);
} 

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;

	ll ans = fact(n);

	ans = (ans * 2 - pw(n) + MOD) % MOD;

	cout << ans;

	return 0;
}
