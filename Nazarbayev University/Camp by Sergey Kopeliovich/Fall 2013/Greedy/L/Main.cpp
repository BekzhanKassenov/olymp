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
#define File "advent"

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

struct z {
 	int h, l, nmb;

 	bool operator < (const z& p) const {
 		return (h + l < p.h + p.l);
 	}
};

istream& operator >> (istream& c, z& p) {
 	c >> p.h >> p.l;
 	return c;
}

z a[100010];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	int n;
	
	cin >> n;

	ll sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i].nmb = i + 1;
		sum += a[i].h;
	}

	int h;
	cin >> h;

	sort(a, a + n);

	int ans = 0;

	vector <int> res;

	for (int i = 0; i < n; i++) {
		if (sum + a[i].l >= h) {
			sum -= a[i].h;
			ans++;
			res.push_back(a[i].nmb);
		}
	}

	cout << ans << endl;

	for (int i = 0; i < ans; i++)
		cout << res[i] << ' ';

	return 0;
}
