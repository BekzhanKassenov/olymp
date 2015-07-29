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

ull fib[10000];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	ull n;
	cin >> n;

	fib[0] = fib[1] = 1;

	int sz = 0;

	for (int i = 2; ; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		sz = i + 1;
		if (fib[i] > n)
			break;
	}

	int k = 0;

	while (n) {
		int pos = upper_bound(fib, fib + sz, n) - 1 - fib;
		n -= pos;
		cout << n << endl;
		k++;
	}

	cout << k;


	return 0;
}