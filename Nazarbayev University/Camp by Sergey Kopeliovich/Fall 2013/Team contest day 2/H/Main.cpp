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
#define File "question"

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

ll d[100];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int l;

		cin >> l;
		int x;

		for (int j = 0; j < l; j++) {
			cin >> x;
			d[i] |= (1ll << x);
		}
	}

	int q;

	cin >> q;

	for (int i = 0; i < q; i++) {
		int l, cur = 1;
		cin >> l;
		ll tot = 0;
		bool cont = 0;
		for (int j = 0; j < l; ++j){
			int x;
			cin >> x;
			while (cur < x) 
				tot |= d[cur++];

		ll tot1 = tot & d[x];
		//cout << tot << " " << tot1 << endl;

		if (__builtin_popcount(tot1) < cur && d[x] == tot1)
			{cont |= 0; break;}
			else
			cont = 1;
		} 
		if (!cont)
			cout << "Yes\n";
			else cout << "No\n";
	}

	return 0;
}
