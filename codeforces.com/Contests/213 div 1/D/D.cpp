/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef unsigned long long ll;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

const int maxn = (int)1e6 + 10;

ll gcd(ll u, ll v) {
 	ll shift;
 
  	if (u == 0) return v;
  	if (v == 0) return u;
 
  	for (shift = 0; ((u | v) & 1ull) == 0; ++shift) {
		u >>= 1;
        v >>= 1;
  	}
 
 	while ((u & 1ull) == 0)
    	u >>= 1;
 
  	do {
		while ((v & 1ull) == 0)             
			v >>= 1;
 
      	if (u > v) {
			ll t = v; v = u; u = t;}  
       	v = v - u;                       
     } while (v != 0);
 
  return u << shift;
}

ll a[maxn];

ll get_ll() {
	char c;

	do {
		c = getchar();
	} while (c < '0' || c > '9');

	ll res = 0;

	do {
	 	res = res * 10ull + c - '0';
	 	c = getchar();
	} while (c >= '0' && c <= '9');

	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	n = (int)get_ll();

	for (int i = 0; i < n; i++)
		a[i] = get_ll();

	sort(a, a + n);

	ll ans = 0;

	for (int i = 0; i < n; i++)
		ans = gcd(ans, a[i]);

	cout << ans;	

	return 0;
}
