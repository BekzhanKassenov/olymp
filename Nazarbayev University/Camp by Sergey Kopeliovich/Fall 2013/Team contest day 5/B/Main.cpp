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

bool cmp(const vector <int>& a, const vector <int>& b) {
	return (a.size() < b.size());
}

const int N = 400;

bool ok(const bitset <N>& a, const bitset <N>& b) {
	for (int i = 0; i < N; i++)
		if (a[i] != b[i])
			return false;

	return true;
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	int n, m;

	while ((cin >> n >> m) && n && m) {
		set <vector <int> > s;
		int k;
		int ans = 0;
		for (int i = 0; i < m; i++) {
			cin >> k;
			vector <int> cur(k);

			for (int j = 0; j < k; j++)
				cin >> cur[j];

			sort(all(cur));

			if (s.count(cur))
				ans++;
			else
				s.insert(cur);	
		}

		vector <vector <int> > tmp(s.begin(), s.end());
		sort(all(tmp), cmp);

		vector <bitset <N> > a(tmp.size());

		for (size_t i = 0; i < tmp.size(); i++) 
			for (size_t j = 0; j < tmp[i].size(); j++) { 
				a[i][tmp[i][j]] = 1;
			}

		for (int i = a.size() - 1; i > 0; i--) {
			bitset<N> cur;
			
			for (int j = i - 1; j >= 0; j--) {
				bitset <N> tmp = (a[j] | a[i]);
				if (ok(tmp, a[i]))
					cur |= a[j];

			}
			
			if (ok(cur, a[i]))
				ans++;	
		}
		cout << ans << endl;
	}

	return 0;
}
