/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "cinema"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

long long gcd(long long a, long long b){
	if (!a || !b)
		return a+b;
		return gcd(b%a, a);
}
int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	long long n, m, d, l, a, b;


	cin >> n >> m;
	d = gcd(n-1, m-1);
	cout << d + 1;
	return 0;
	a = (n-1)/d;
	b = (m-1)/d;
	 cout << min((n-1)/a, (m-1)/b)+1;
	     /*

	if (n == m) cout << n;
	else if (n == 1 || m == 1) cout << (m + n - 1);
	else if (n % 2 == 1 && m % 2 == 1) cout << 3;
	else cout << 2;            */

	return 0;
}
