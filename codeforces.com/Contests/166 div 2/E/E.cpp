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
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

ll gcd(ll a, ll b) {
 	if (a == 0 || b == 0)
 		return a + b;

 	return gcd(b, a % b);	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	ll x, g = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;
		g = gcd(g, x - 1);
	}

	ll ans = 0;

	for (ll i = 1; i * i <= g; i++) {
		if (g % i == 0) {
			if (i & 1) {
				ll power = 1;

				while (power * i <= m) {
					ans += m - power * i;
					power *= 2;
				}
			}

			if (i * i != g) {
				ll d = g / i;

				if (d & 1) {
					ll power = 1;

					while (power * d <= m) {
						ans += m - power * d;
						power *= 2;
					}
				}
			}
		}
	}

	cout << ans;

	return 0;
}
