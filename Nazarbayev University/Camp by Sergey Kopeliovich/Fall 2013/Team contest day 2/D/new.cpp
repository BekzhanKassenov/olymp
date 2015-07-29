/****************************************
**         Solution by NU_02           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd
#define File "fib"

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

ll fib[100];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	ll n;
	cin >> n;

	fib[0] = 1;
	fib[1] = 1;
		fib[2] = 2;
		         	fib[3] = 3;


	int sz = 2;

	for (int i = 2; ; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		sz = i;
		if (fib[i] > n)
			break;
	}
	while (fib[sz] > n)
		sz--;
	ll ans = 0;

	while (n > 0) {
	if (sz == 0)
	{
		break;
	}
      ans +=  ((n-fib[sz])/sz+1);
	  n -= ((n-fib[sz])/sz+1)*sz;
	 	while (fib[sz] > n)
	  sz--;
	}

	cout << ans;

	return 0;
}
