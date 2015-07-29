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
#define File "blot"

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

int n, m;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool ok(int x, int y) {
  	return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs(int i, int j, vector <vector <bool> >& a, vector <vector <bool> >& used) {
	queue <PII> q;

	q.push(MP(i, j));
	used[i][j] = true;

	int ans = 1;

	while (!q.empty()) {
		i = q.front().F;
		j = q.front().S;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if (ok(x, y) && !used[x][y] && a[x][y]) {
				ans++;
				used[x][y] = true;
				q.push(MP(x, y));
			}
		}
	}

	return ans;
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	vector <vector <bool> > a(n, vector <bool> (m)), used = a;

	char c = getchar();

	int cnt = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c = getchar();
			a[i][j] = (c == '1');
		}
		c = getchar();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] && !used[i][j]) {
				cnt++;
				ans = max(ans, bfs(i, j, a, used));
			}
		}
	}

	printf("%d %d\n", cnt, ans);

	return 0;
}
