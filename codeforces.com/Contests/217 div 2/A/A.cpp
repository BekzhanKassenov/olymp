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

int dist[10][10];

bool ok(int x, int y) {
 	return (x >= 0 && x < 10 && y >= 0 && y < 10);
}

void bfs(int x, int y) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			dist[i][j] = INF;

	dist[x][y] = 0;
	queue <PII> q;
	q.push(MP(x, y));

	while (!q.empty()) {
		PII cur = q.front();
		q.pop();

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i != 0 || j != 0) {
					PII tmp(cur.F + i, cur.S + j);

					if (ok(tmp.F, tmp.S) && dist[tmp.F][tmp.S] == INF) {
						dist[tmp.F][tmp.S] = dist[cur.F][cur.S] + 1;
						q.push(tmp);
					}
				}
			}
		}
	}
} 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int r1, r2, c1, c2;

	cin >> r1 >> c1 >> r2 >> c2;

	if (r1 == r2 || c1 == c2)
		cout << 1;
	else
		cout << 2;

	cout << ' ';

	if ((r1 + c1) % 2 != (r2 + c2) % 2) 
		cout << 0;
	else {
		if (abs(r2 - r1) == abs(c2 - c1))
			cout << 1;
		else
			cout << 2;	
	}	
	cout << ' ';

	bfs(r1, c1);
	cout << dist[r2][c2] << endl;

	return 0;
}
