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
#define File "people"

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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

PII t[8 * maxn];
int n, d[maxn], pr[maxn], maxnum;

struct st {
 	int s, b, num;

 	st() { }

 	void read() {
 		scanf("%d%d", &s, &b);
 	}

 	bool operator < (const st& rhs) const {
 		return s < rhs.s;
 	}
};

st a[maxn];

void update(int v, int l, int r, int pos, PII val) {
	if (l > r || pos < l || pos > r)
		return;

	if (l == r && pos == l) {
		if (val.F > t[v].F)
			t[v] = val;
		return;
	}
	
	int mid = (l + r) >> 1;

	update(v << 1, l, mid, pos, val);
	update((v << 1) + 1, mid + 1, r, pos, val);

	if (t[v << 1].F > t[(v << 1) + 1].F)
		t[v] = t[v << 1];
	else
		t[v] = t[(v << 1) + 1];	
}

PII get(int v, int l, int r, int z_r) {
	if (l > r || l > z_r)
		return MP(0, 0);

	if (r <= z_r)
		return t[v];

	int mid = (l + r) >> 1;

	PII lhs = get( v << 1     , l      , mid, z_r);
	PII rhs = get((v << 1) + 1, mid + 1, r  , z_r);

	if (lhs.F > rhs.F)
		return lhs;

	return rhs;
}

void compress() {
	vector <int> nmbs;

	for (int i = 0; i < n; i++) {
		nmbs.push_back(a[i].s);
		nmbs.push_back(a[i].b);
	}

	sort(all(nmbs));
	nmbs.resize(unique(all(nmbs)) - nmbs.begin());

	map <int, int> Map;

	for (size_t i = 0; i < nmbs.size(); i++) {
		Map[nmbs[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		a[i].s = Map[a[i].s];
		a[i].b = Map[a[i].b];
	}

	maxnum = nmbs.size();
}

void calc(int pos) {
	PII q = get(1, 0, maxnum, a[pos].b - 1);

	if (q.F == 0) {
		d[pos] = 1;
		pr[pos] = pos;
	} else {
		d[pos] = 1 + q.F;
		pr[pos] = q.S;
	}
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		a[i].read();
		a[i].num = i + 1;
	}

	compress();
	sort(a, a + n);

	int pos = 0;

	while (pos < n) {	
		int npos = pos;
		do {
			calc(npos);
			npos++;
		} while (npos < n && a[npos].s == a[pos].s); 


		while (pos < npos) {
			update(1, 0, maxnum, a[pos].b, MP(d[pos], pos));

			pos++;
		}
	} 

	int anspos = 0;

	for (int i = 1; i < n; i++) {
		if (d[i] > d[anspos])
			anspos = i;
	}

	vector <int> res;

	do {
		res.push_back(a[anspos].num);
		anspos = pr[anspos];
	} while (pr[anspos] != anspos);

	res.push_back(a[anspos].num);

	cout << res.size() << endl;
	
	for (size_t i = 0; i < res.size(); i++)
		cout << res[i] << ' ';

	return 0;
}
