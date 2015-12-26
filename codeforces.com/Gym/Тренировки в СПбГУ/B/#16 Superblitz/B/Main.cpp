/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXM = 100010;
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
pair <int, int> e[MAXM];
bool used[MAXN];
int tin[MAXN], tout[MAXN], timer;
int comp[MAXN], cnum;
set <int> ans[MAXN];
vector <int> g[MAXN], g_tr[MAXN];

void dfs(int v, vector <int>& order) {
 	used[v] = true;
 	tin[v] = timer++;

 	for (size_t i = 0; i < g[v].size(); i++) {
 	 	int to = g[v][i];
 	 	if (!used[to]) {
 	 	 	dfs(to, order);
 	 	}
 	}

 	order.push_back(v);
 	tout[v] = timer++;
}

void dfs_comp(int v, int cnum) {
 	comp[v] = cnum;
 	used[v] = true;

 	for (size_t i = 0; i < g_tr[v].size(); i++) {
 	 	int to = g_tr[v][i];
 	 	if (!used[to]) {
 	 	 	dfs_comp(to, cnum);
 	 	}
 	}
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
     	scanf("%d%d", &e[i].first, &e[i].second);
     	e[i].first--;
     	e[i].second--;
     	g[e[i].first].push_back(e[i].second);
     	g_tr[e[i].second].push_back(e[i].first);
    }

    vector <int> order;
    for (int i = 0; i < n; i++) {
     	if (!used[i]) {
     	 	dfs(i, order);
     	}
    }
    
    memset(used, false, sizeof used);
    for (int i = n - 1; i >= 0; i--) {
		if (!used[order[i]]) {
		 	dfs_comp(order[i], cnum);
		 	cnum++;
		}
    }

    for (int i = 0; i < m; i++) {
    	if (comp[e[i].first] != comp[e[i].second]) {
    		ans[comp[e[i].first]].insert(comp[e[i].second]);
		}
    }

    int result = 0;
    for (int i = 0; i < cnum; i++) {
    	result += ans[i].size();
	}

	printf("%d\n", result);
    return 0;
}
