/****************************************
**     Solution by Bekzhan Kassenov    **
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
const int maxn = 100010;
const ll INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

#define F first
#define S second
#define MP make_pair

vector <pair <int, int> > g[maxn];
ll sum;
bool used[maxn], has_big_comp;
int n, m, p, q, x, y, cost;

set <pair <long long, vector <int> > > s;

void dfs(int v, vector <int>& comp) {
	comp.push_back(v);
	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++) {
		int to = g[v][i].F;
		if (!used[to])
			dfs(to, comp);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d%d%d", &n, &m, &p, &q);

	if (n == 1 && p > 0) {
		cout << "NO";
		return 0;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &cost);
		g[--x].push_back(MP(--y, cost));
		g[y].push_back(MP(x, cost));
	}

	vector <int> cmp;

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, cmp);
			sort(all(cmp));
			ll sum = 0;

			for (size_t j = 0; j < cmp.size(); j++) {
				for (size_t k = 0; k < g[cmp[j]].size(); k++)
					sum += g[cmp[j]][k].S;
			}
			sum >>= 1;
			s.insert(MP(sum, cmp));
			cmp.clear();
		}
	}

	int cnt = s.size();

	if (q > cnt) {
		cout << "NO";
		return 0;
	}

	stringstream sstr;

	while (cnt > q) {	
		pair <long long, vector <int> > ff = *s.begin(), ss;
		p--;
		s.erase(s.begin());
		ss = *s.begin();
		s.erase(s.begin());

		ll new_sum = ff.F + ss.F + min(INF, ff.F + ss.F + 1);

		sstr << ff.S[0] + 1 << ' ' << ss.S[0] + 1 << endl;

		vector <int> new_vec;
		merge(all(ff.S), all(ss.S), back_inserter(new_vec));
		s.insert(MP(new_sum, new_vec));
		if (p < 0) {
			cout << "NO";
			return 0;
		}
		cnt--;
	}

	set <pair <long long, vector <int> > > :: iterator it = s.begin();

	for (; it != s.end(); it++) {
	 	if ((it -> S).size() > 1)
	 		break;
	}

	
	if (it == s.end()) {
		if (cnt != q) {
			cout << "NO";
			return 0;
		}

		int first_ver = (s.begin() -> S)[0];
		s.erase(s.begin());
		int second_ver = (s.begin() -> S)[0];

		while (p --> 0) {
			sstr << first_ver + 1 << ' ' << second_ver + 1 << endl;
		}
	}

	while (p --> 0) {
		sstr << (it -> S)[0] + 1 << ' ' << (it -> S)[1] << endl;
	}

	cout << "YES" << endl;
	cout << sstr.str();
	
	return 0;
}
