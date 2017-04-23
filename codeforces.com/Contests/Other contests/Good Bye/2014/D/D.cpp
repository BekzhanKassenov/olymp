/****************************************
**     Solution by Bekzhan Kassenov    **
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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
  	int from, to, len;
  	int sub;

  	void read() {
  	 	scanf("%d%d%d", &from, &to, &len);
  	 	sub = 0;
  	}
};

int n;
Edge e[MAXN];
vector <int> g[MAXN];
int size[MAXN];
double prob[MAXN];
double cur;
int m, r, w;

void dfs(int v, int pr = 0) {
 	size[v] = 1;

 	for (size_t i = 0; i < g[v].size(); i++) {
 	 	int to = e[g[v][i]].from + e[g[v][i]].to - v;

 	 	if (to != pr) {
 	 		dfs(to, v);
 	 		size[v] += size[to];
 	 	}
 	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
	
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
	 	e[i].read();
	 	g[e[i].from].push_back(i);
	 	g[e[i].to].push_back(i);
	}

	dfs(1);
	for (int i = 0; i < n - 1; i++) {
	 	double subtree = min(size[e[i].to], size[e[i].from]);
		prob[i] = 6.0 * (subtree * n - sqr(subtree)) / (sqr(n + .0) - n);
		cur += prob[i] * e[i].len;
	}

	scanf("%d", &m);
	while (m--) {
	 	scanf("%d%d", &r, &w);
	 	r--;
	 	cur -= prob[r] * e[r].len;
	 	e[r].len = w;
	 	cur += prob[r] * e[r].len;

	 	printf("%.14lf\n", cur);
	}

	
	return 0;
}
