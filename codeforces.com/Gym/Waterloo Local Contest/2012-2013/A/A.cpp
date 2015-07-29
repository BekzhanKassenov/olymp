#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

#define MP make_pair

struct edge {
 	int to;
 	ll cost;
 	bool inside;

 	edge() {}

 	edge(int to, ll cost, bool inside) : to(to), cost(cost), inside(inside) {}
};

const ll INF = (ll)1e12;

struct dst {
 	ll inside, outside;

	dst() : inside(INF), outside(INF) {}

	dst(ll inside, ll outside) : inside(inside), outside(outside) {}	
	
	bool operator < (const dst& a) const {
		if (outside != a.outside)
			return outside < a.outside;

		return inside < a.inside;
	}

	bool operator != (const dst& a) const {
		return (inside != a.inside || outside != a.outside);
	}
};

dst dist[4010][4010];
vector <edge> g[4010];
bool used[4010];
dst empt;

void output(int v, int to) {
	if (dist[v][to] != empt)
		cout << dist[v][to].outside << ' ' << dist[v][to].outside + dist[v][to].inside << endl;
	else
		cout << "IMPOSSIBLE";
}

void dijkstra(int vs, int to) {
	if (used[vs]) {
		output(vs, to);
		return;
	}

	set <pair <dst, int> > s;
	dist[vs][vs].inside = 0;
	dist[vs][vs].outside = 0;
	s.insert(MP(dist[vs][vs], vs));

	while (!s.empty()) {
		int v = s.begin() -> second;
		s.erase(s.begin());

		for (size_t i = 0; i < g[v].size(); i++) {
			edge cur = g[v][i];

			dst ndst = dist[vs][v];
			if (cur.inside)
				ndst.inside += cur.cost;
			else
				ndst.outside += cur.cost;

			if (ndst < dist[vs][cur.to]) {
				s.erase(MP(dist[vs][cur.to], cur.to));
				dist[vs][cur.to] = ndst;
				s.insert(MP(ndst, cur.to));
			}
		}
	}

	used[vs] = true;
	output(vs, to); 
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m, p;

	cin >> n >> m >> p;

	int from, to;
	ll cost;
	bool in;
	char c;

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost >> c;
		in = (c == 'I');

		g[from].push_back(edge(to, cost, in));
		g[to].push_back(edge(from, cost, in));
	}

	for (int i = 0; i < p; i++) {
	  	cin >> from >> to;
	  	dijkstra(from, to);
	}

	return 0;
}
