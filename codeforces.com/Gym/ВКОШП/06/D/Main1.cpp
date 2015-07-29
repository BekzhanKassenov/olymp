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
#define File "elect"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}
const int maxn = 100010;

struct str {
 	int v, p, nmb;

 	bool operator < (const str& a) const {
 		return (v < a.v);
 	}
};

istream& operator >> (istream& c, str& s) {
	c >> s.v >> s.p;
	return c;
}

PII a[maxn];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i].nmb = i + 1;
	}

	sort(a, a + n);
	reverse(a, a + n);

	ll ans = INF;

	for (int i = 0; i < n; i++) {
		if (a[i].p != -1) {
			
		}
	}

	return 0;
}
