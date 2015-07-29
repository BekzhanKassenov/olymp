#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MP make_pair
#define F first
#define S second

const int maxn = 50010;
const int maxm = 150010;
bool used[maxn];
vector <pair <int, int> > g[maxn];
int number[maxm], deg[maxn], n, m, x, y, cur_number;

void dfs(int v) {
	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++) {
		int to = g[v][i].F;
		int numb = g[v][i].S;

		if (!number[numb])
			number[numb] = ++cur_number;

		if (!used[to])
			dfs(to);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		g[--x].push_back(MP(--y, i));
		g[y].push_back(MP(x, i));
		deg[x]++, deg[y]++;
	}

	bool started = false;

	for (int i = 0; i < n; i++) {
		if (deg[i] == 1) {
			if (!started) {
				dfs(i);
				started = true;
			} else {
				puts("IMPOSSIBLE");
				return 0;
			}	
		}
	}

	if (!started) 
		dfs(0);

	for (int i = 0; i < m; i++)
		printf("%d\n", number[i]);

	return 0;	
}
