/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> 
inline T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
	return (n * n);
}
const int maxn = 100010;
vector <int> g[maxn], lca[maxn];
int n, m, d, a, b, l, dist[maxn], p[maxn], tin[maxn], tout[maxn], timer;

void dfs(int v, int pr = -1) {
	if (pr != -1) {
		dist[v] = dist[pr] + 1;
		lca[v][0] = pr;
	}

	tin[v] = ++timer;

	for (int i = 1; i <= l; i++)
		lca[v][i] = lca[lca[v][i - 1]][i - 1];

   	for (size_t i = 0; i < g[v].size(); i++)
   		if (g[v][i] != pr)
   			dfs(g[v][i], v);

  	tout[v] = ++timer;
}

bool upper(int aa, int bb) {
	return (tin[aa] <= tin[bb] && tout[aa] >= tout[bb]);
}

int get_lca(int aa, int bb) {
	if (upper(aa, bb))
		return aa;

   	if (upper(bb, aa))
   		return bb;

	for (int i = l; i >= 0; i--) {
		if (!upper(lca[aa][i], bb))
			aa = lca[aa][i];
	}

	return lca[aa][0];
}

int get_dist(int aa, int bb) {
	int lc = get_lca(aa, bb);

	return (dist[aa] + dist[bb] - (dist[lc] << 1));
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d%d", &n, &m, &d);

	for (int i = 0; i < m; i++)
		scanf("%d", &p[i]);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a, &b);

		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	while ((1 << l) <= n)
		l++;

	for (int i = 0; i < n; i++)
		lca[i].resize(l + 1);

   	dfs(0);

   	set <int> s;

   	for (int i = 0; i < n; i++)
   		if (get_dist(i, p[0]) <= d) {
   			s.insert(i);
   		}

   	for (int i = 1; i < m; i++) {
   		vector <int> v(s.begin(), s.end());

   		s.clear();

   		for (size_t j = 0; j < v.size(); j++)
   			if (get_dist(v[j], p[i]) <= d)
   				s.insert(v[j]);
   	}

   	cout << s.size() << endl;

	return 0;
}
