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
#define File "prizes"

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

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int a, b;

	cin >> a >> b;

	if (a > b) swap (a, b);

	if (a == 1 && b <= 2) 
		cout << 0;
	else if (a == 1) 
		cout << 1 + (b - 3) / 4;
	else 
		cout << (a >= 3 ? (1 + (a - 3) / 4) : 0);

	return 0;
}

