#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define INF (int)1e9

int n, m, g[510][510];

PII dist[510][510];

int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};
                                    
inline bool ok(const PII &a) {
	return ((a.F >= 0 && a.F < n && a.S >= 0 && a.S < m));
}

inline bool relax(PII &a, const PII &b) {
	if (a.F > b.F || (a.F == b.F && a.S > b.S)) {
		a = b;
		return true;
	}
	
	return false;
}

struct vertex {
 	PII first, second;

 	vertex() {}

 	vertex(PII a, PII b) : first(a), second(b) {}
};

inline bool operator < (const vertex &a, const vertex &b) {
	if (a.S == b.S)	
		return (a.F < b.F ? true : false);

	if (a.S.F > b.S.F || (a.S.F == b.S.F && a.S.S > b.S.S))
		return true;

	return false;	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	int xs, ys, xf, yf;

	cin >> xs >> ys >> xf >> yf;

	xs--, ys--, xf--, yf--;

	PII z = MP(INF, INF);
	char c;

	for (int i = 0; i < n; i++) {
		getchar();

		for (int j = 0; j < m; j++) {
			c = getchar();

			g[i][j] = c - '0';

			dist[i][j] = z;
		}
	}

	priority_queue <vertex> q;

	q.push(vertex(MP(xs, ys), MP(0, 1)));

	dist[xs][ys] = MP(0, 1);

	while (!q.empty()) {
		PII cur = q.top().F;

		PII tmp = q.top().S;

		q.pop();

		if (tmp != dist[cur.F][cur.S])
			continue;

		for (int i = 0; i < 8; i++) {
			tmp = MP(cur.F + dx[i], cur.S + dy[i]);

			if (ok(tmp) && g[tmp.F][tmp.S] != 0) {
				PII cnt = dist[cur.F][cur.S];

				cnt.S++;

				if (g[tmp.F][tmp.S] != g[cur.F][cur.S])
					cnt.F++;

				if (relax(dist[tmp.F][tmp.S], cnt))
					q.push(vertex(tmp, cnt));
			}
		}
	}

	if (dist[xf][yf] == MP(INF, INF))
		puts("0 0");
	else
		cout << dist[xf][yf].S << ' ' << dist[xf][yf].F;

	return 0;	
}
