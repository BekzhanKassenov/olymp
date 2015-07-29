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
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

struct stud {
 	int pos;
 	int level, cost;

 	stud() { }

 	stud(int pos, int level, int cost) : pos(pos), level(level), cost(cost) { }

 	inline bool operator < (const stud& st) const {
 		return (cost < st.cost);
 	}
};

struct bug {
 	int pos;
 	int level;

 	bug() { }

 	bug(int pos, int level) : pos(pos), level(level) { }

 	inline bool operator < (const bug& bg) const {
 		return (level > bg.level);
 	}
};


inline bool stud_cmp(const stud& s1, const stud& s2) {
 	return s1.level > s2.level;
}

const int maxn = 100010;

int n, m, s, ans[maxn];
bug bg[maxn];
stud st[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	
	ios_base :: sync_with_stdio(false);

	cin >> n >> m >> s;

	for (int i = 0; i < m; i++) {
		cin >> bg[i].level;
		bg[i].pos = i;
	}

	sort(bg, bg + m);

	for (int i = 0; i < n; i++) {
		cin >> st[i].level;
	}

	for (int i = 0; i < n; i++) {
		cin >> st[i].cost;
		st[i].pos = i;
	}

	sort(st, st + n, stud_cmp);

	if (st[0].level < bg[0].level) {
	 	cout << "NO";
	 	return 0;
	}

	set <stud> q;
	set <bug> q1(bg, bg + m);

	int curc = 0;
	int pos = 0;
	vector <int> poss;

	for (int i = 0; i < m; i++) {
		while (st[pos].level >= bg[i].level) {
			q.insert(st[pos++]);
		}

		if (i >= 0) {
			cout << bg[i].level << endl;

			for (set <stud> :: iterator it = q.begin(); it != q.end(); it++)
				cout << it -> pos + 1 << endl;
				cout << endl;
		}

		if (q.empty()) {
			continue;
		}

		stud res = *q.begin();

		q.erase(q.begin());

		if (curc + res.cost > s) {
			break;
		} else {
			curc += res.cost;
			ans[bg[i].pos] = res.pos;
			q1.erase(bg[i]);
			poss.push_back(res.pos);
		}
	}

	for (int i = 0; i < poss.size(); i++)
		cout << poss[i] << endl;

	int len = poss.size();
	int p1 = 0;

	while (!q1.empty()) {
		bug res = *q1.begin();
		q1.erase(q1.begin());

		ans[res.pos] = poss[p1];
		p1++;
		p1 %= len;
	}

	cout << "YES" << endl;

	for (int i = 0; i < m; i++)
		cout << ans[i] + 1 << ' ';


	return 0;
}
