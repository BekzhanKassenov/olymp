#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100010;

vector <vector <int> > a, nmb;
vector <int> g[maxn], lca[maxn];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int n, m, cnt, l, timer, tin[maxn], tout[maxn], dist[maxn];

bool upper(int a, int b) {
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y, int p_x = 0, int p_y = 0, int d_pr = -1) {
	nmb[x][y] = cnt++;
	int numb = nmb[x][y];
	int pr_nmb = 0;

	cout << x + 1 << ' ' << y + 1 << endl;

	if (d_pr != -1) {
		pr_nmb = nmb[p_x][p_y];
		g[pr_nmb].push_back(numb);
		g[numb].push_back(pr_nmb);
	}

	lca[numb][0] = pr_nmb;

	for (int i = 1; i <= l; i++) 
		lca[numb][i] = lca[lca[numb][i - 1]][i - 1];

	for (int i = 0; i < 4; i++) {
		int tmp_x = x + dx[i];
		int tmp_y = y + dy[i];

		if ((tmp_x != p_x || tmp_y != p_y || d_pr == -1) && ok(tmp_x, tmp_y) && a[tmp_x][tmp_y] == 1) {
			dfs(tmp_x, tmp_y, x, y, i);
			if (d_pr != -1 && i != d_pr) 
				dist[nmb[tmp_x][tmp_y]] = dist[numb] + 1;
			else
				dist[nmb[tmp_x][tmp_y]] = dist[numb];
		}	
	}
}

int get_lca(int a, int b) {
	if (upper(a, b))
		return a;

	if (upper(b, a))
		return b;

	for (int i = l; i >= 0; i--)
		if (!upper(lca[a][i], b))
			a = lca[a][i];

	return lca[a][0];
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d", &n, &m);

	a.resize(n, vector <int> (m));
	nmb = a;

	char c = getchar();

	int cn = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c = getchar();
			a[i][j] = (c == '#');
			cn += a[i][j];
		}
		getchar();
	}

	while ((1 << l) <= cn)
		l++;

	for (int i = 0; i < cn; i++)
		lca[i].resize(l + 1);

	bool flag = true;

	for (int i = 0; i < n && flag; i++)
		for (int j = 0; j < m && flag; j++)
			if (a[i][j] == 1) {
				dfs(i, j);
				flag = false;
			}

	int k;

	scanf("%d", &k);

	while (k--) {
		int x, y, _x, _y;

		scanf("%d%d%d%d", &x, &y, &_x, &_y);
		x--, y--, _x--, _y--;

		int anc = get_lca(nmb[x][y], nmb[_x][_y] + 1);

		printf("%d\n", dist[nmb[x][y]] + dist[nmb[_x][_y]] - 2 * dist[ans]);
	}

	return 0;
}
