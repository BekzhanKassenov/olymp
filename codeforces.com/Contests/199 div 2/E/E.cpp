/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
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
inline T sqr(T n) {
	return (n * n);
}

const int maxn = 100010;

int t, z, n, m, x, y, dist[maxn];
vector <int> g[maxn];

void dfs(int v, int pr = -1) {
	if (pr != -1) {
		if (dist[v] > dist[pr] + 1) {
			dist[v] = dist[pr] + 1;
		} else
			return;
	}

	for (size_t i = 0; i < g[v].size(); i++) {
		if (g[v][i] != pr)
			dfs(g[v][i], v);
	}
}

struct que {
 	PII a[maxn];

 	int head, tail;

 	que() : head(0), tail(0) {}

 	void push(PII n) {
 		a[tail++] = n;
 	}

 	void pop() {
 		head++;
 	}

 	PII front() {
 		return a[head];
 	}

 	bool empty() {
 		return (head > tail);
 	}

 	void clear() {
 		head = tail = 0;
 	}
};

que q;

void bfs(int v) {
	q.clear();
	q.push(MP(v, -1));

	while (!q.empty()) {
		int cur = q.front().F;
		int pr = q.front().S;
		q.pop();

		if (pr != -1) {
			dist[cur] = min(dist[cur], dist[pr] + 1);
		}

		for (size_t i = 0; i < g[cur].size(); i++) {
			if (g[cur][i] != cur && dist[g[cur][i]] > dist[cur] + 1) {
				q.push(MP(g[cur][i], cur));
			}                              
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &x, &y);

		g[--x].push_back(--y);
		g[y].push_back(x);
	}

	memset(dist, INF, sizeof dist);

	dfs(0);

	stringstream ss;

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &t, &z);
		z--;

		if (t == 1) {
			dist[z] = 0;
			bfs(z);
		} else 
			ss << dist[z] << endl;

		//if (i % 1000 == 0) {
		//	cout << i << endl;
		//}
	}

	cout << ss.str() << endl;

	return 0;
}
