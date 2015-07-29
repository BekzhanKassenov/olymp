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

struct st {
 	int coord, pos;
 	bool open;

 	st() { }

 	st(int coord, int pos, bool open) : coord(coord), pos(pos), open(open) { }

 	bool operator < (const st& p) const {
 		return coord < p.coord;
 	}
};

int one[500010];
map <pair <int, int>, int> two;

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <pair <int, int> > a(n);

	for (int i = 0; i < n; i++) 
		cin >> a[i].F >> a[i].S;

	vector <st> b(2 * n);

	for (int i = 0; i < n; i++) {
		b[i << 1] = st(a[i].F, i, true);

		b[(i << 1) + 1] = st(a[i].S, i, false);
	}

	sort(all(b));

	set <int> st;

	int sz = 0;

	for (int i = 0; i < 2 * n; i++) {
		if (st.empty() || b[i].open) {
			st.insert(b[i].pos);
			sz++;
		} else if (!b[i].open) {
			st.erase(b[i].pos);
			sz--;
		}

		if (sz == 1 && i < 2 * n - 1) {
			one[*st.begin()] += (b[i + 1].coord - b[i].coord);
		} else if (sz == 2 && i < 2 * n - 1) {
			set <int> :: iterator it = st.begin();
			pair <int, int> pr;
			pr.F = *it;
			it++;
			pr.S = *it;
			two[pr] += (b[i + 1].coord - b[i].coord);
		}
	}

	int mx = -1, mx1 = -1;

	for (int i = 0; i < n; i++) {
		if (one[i] > mx) {
			mx1 = mx;
			mx = one[i];
		} else if (one[i] > mx1) {
			mx1 = one[i];
		}
	}

	/*for (int i = 0; i < n; i++) {
		cout << i << ' ' << one[i] << endl;
	}

	cout << endl;*/

	int ans = mx1 + mx;

	for (map <pair <int, int>, int> :: iterator it = two.begin(); it != two.end(); it++) {
		//cout << (it -> F).F << ' ' << (it -> F).S << ' ' << it -> S  << endl;

		ans = max(ans, it -> S + one[(it -> F).F] + one[(it -> F).S]);
	}

	cout << ans;
	
	return 0;
}
