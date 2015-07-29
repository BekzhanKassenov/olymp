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

char table[8][8];
int t, xs, ys, xf, yf;
int dist[8][8], dist1[8][8];

int dx[4] = {2, 2, -2, -2};
int dy[4] = {-2, 2, -2, 2};

bool ok(int x, int y) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void bfs(int x, int y, int d[8][8]) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			d[i][j] = INF;

	d[x][y] = 0;

	queue <pair <int, int> > q;
	q.push(MP(x, y));

	while (!q.empty()) {
		PII cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			PII tmp(cur.F + dx[i], cur.S + dy[i]);

			if (ok(tmp.F, tmp.S) && dist[tmp.F][tmp.S] > dist[cur.F][cur.S] + 1) {
				dist[tmp.F][tmp.S] = dist[cur.F][cur.S] + 1;
				q.push(tmp);
			}
		}
	}   
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> t;

	while (t--) {
		xs = -1, xf = -1;
		for (int i = 0; i < 8; i++) 
			for (int j = 0; j < 8; j++) {
				cin >> table[i][j];
				if (table[i][j] == 'K') {
					if (xs == -1)
						xs = i, ys = j;
					else
						xf = i, yf = j;
				}
			}
		bfs(xs, ys, dist);
		bfs(xf, yf, dist1);

		int ans = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (dist[i][j] != INF && dist1[i][j] != INF && table[i][j] != '#' && dist[i][j] % 2 == dist1[i][j] % 2)
					ans++;
			}
		}

		if (ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;	
	}
                    

	return 0;
}
