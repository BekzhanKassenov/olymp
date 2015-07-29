/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
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
inline T sqr(T n) {
	return (n * n);
}

ll gcd(ll a, ll b) {
	if (!a || !b)
		return a + b;

	return (gcd(b % a, a));
}

ll calc(ll a, ll b) {
	if (a == b)
		return 1;

	ll res = 0;

	ll g = 0;

	while (a > 1 || b > 1) {
		g = gcd(a, b);
		a /= g;
		b /= g;

		if (a < b) 
			swap(a, b);

	   	res += a / b;
	   	a %= b;
	}

	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ll a, b;

	cin >> a >> b;
	
	cout << calc(a, b);

	return 0;
}
