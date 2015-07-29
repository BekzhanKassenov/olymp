#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <bitset>

using namespace std;

const int MAXN = 105000;

int n;
vector <int> g[MAXN];
int ans[MAXN];
bool used[MAXN];
int deg[MAXN];
int root;
int num, to;

void dfs(int v, int dir) {
	used[v] = true;
	ans[v] = dir;
	for (int i = 0; i < (int) g[v].size(); i++) {
		int to = g[v][i];
		if (!used[to])
			dfs(to, 3 - dir);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d %d", &n, &root);
	for (int i = 1; i <= n; i++) {	
		scanf("%d", &num);
		deg[i] = num;
		for (int j = 1; j <= num; j++) {
			scanf("%d", &to);
			g[i].push_back(to);
		}
	}

	dfs(root, 1);

	for (int i = 1; i <= n; i++) {
		if (deg[i] > 1)
			continue;
		if (ans[i] == 0) 
			puts("-");
		else if (ans[i] == 1)
			puts("CW");
		else
			puts("CCW");
	}

	return 0;
}