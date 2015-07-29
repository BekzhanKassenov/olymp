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
#define File "dwarfs"

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

const int maxn = 100010;

struct z {
 	int a, b, nmb;

 	bool operator < (const z& p) const {
 		return (a + b < p.a + p.b);
 	}
};
 
z ar[maxn];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> ar[i].a >> ar[i].b;
		ar[i].nmb = i + 1;
	}

	sort(ar, ar + n);

	ll sum = 0;

	for (int i = 0; i < n; i++) 
		sum += ar[i].a;

	for (int i = n - 1; i >= 0; i--) {
		if (ar[i].a + ar[i].b <= sum) {
			cout << -1;
			return 0;
		}
		sum -= ar[i].b;
	}


	for (int i = n - 1; i >= 0; i--)
		cout << ar[i].nmb << ' ';


	return 0;
}
