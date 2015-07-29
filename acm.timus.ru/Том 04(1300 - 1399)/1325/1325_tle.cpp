#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define int long long 
typedef int _int;

#define PII pair <int ,int >
#define F first
#define S second
#define MP make_pair
#define INF (int)1e9

inline bool relax(PII &a, PII b) {
	if (a.first > b.first || (a.first == b.first && a.second > b.second)) {
		a = b;
		return true;
	}

	return false;
}   

int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};

int n, m;

inline bool ok(PII &a) {
	return (a.first >= 0 && a.first < n && a.second >= 0 && a.second < m); 
}

PII q[3000000], dist[510][510];
int g[510][510];
bool inque[510][510];

int head, tail;

main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	scanf("%I64d%I64d", &n, &m);

   	int xs, ys, xf, yf;

   	scanf("%I64d%I64d%I64d%I64d", &xs, &ys, &xf, &yf);

   	xs--, ys--, xf--, yf--;   

   	char c;

   	PII z = MP(INF, INF);

   	for (int i = 0; i < n; i++) {
   		c = getchar();
   		for (int j = 0; j < m; j++) {
   			c = getchar();

   			g[i][j] = c - '0';
   			dist[i][j] = z;
   		}
   	}

   	q[tail++] = MP(xs, ys);

   	dist[xs][ys] = MP(0, 1);

   	inque[xs][ys] = true;

   	while (head < tail) {
   	 	PII cur = q[head++];
   	 	inque[cur.F][cur.S] = false;

   	 	for (int i = 0; i < 8; i++) {
   	 		PII tmp(MP(cur.F + dx[i], cur.S + dy[i]));
   	 		
   	 		if (ok(tmp) && g[tmp.F][tmp.S] != 0) {
   	 			PII cnt = dist[cur.F][cur.S];

   	 			if (g[tmp.F][tmp.S] != g[cur.F][cur.S])
   	 				cnt.F++;

   	 			cnt.S++;

   	 			if (relax(dist[tmp.F][tmp.S], cnt) && !inque[tmp.F][tmp.S]) {
   	 				q[tail++] = tmp;
   	 				inque[tmp.F][tmp.S] = true;
   	 			}
   	 		}
   	 	}
   	}

   	if (dist[xf][yf] == MP(INF, INF))
   		puts("0 0");
   	else
   		cout << dist[xf][yf].S << ' ' << dist[xf][yf].F;

   	return 0;
}

