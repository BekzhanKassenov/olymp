/****************************************
**         Solution by NU_02           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd
#define File "roads"

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

int g[100][100], dist[100], n;

void bfs(int v) {
	for (int i = 0; i < n; i++)
		dist[i] = INF;

	dist[v] = 0;
	queue <int> q;
	q.push(v);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			if (g[cur][i] && dist[i] > dist[cur] + 1) {
				dist[i] = dist[cur] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	cin >> n;

	char c;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> c;
			g[i][j] = (c == '1');
		}

	bfs(0);

	int pos = 0;

	for (int i = 1; i < n; i++)
		if (dist[pos] < dist[i])
			pos = i;

	bfs(pos);

	int r = 0;

	for (int i = 1; i < n; i++) {
		if (dist[i] > dist[r])
			r = i;
	}

	//cout << pos << ' ' << r << ' ' << dist[r] << endl;

	cout << (n - 1 - dist[r] + n - dist[r]);

	return 0;
}
