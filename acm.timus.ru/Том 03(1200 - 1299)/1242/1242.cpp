#include <iostream>
#include <cstdio>
#include <assert.h>
#include <vector>

using namespace std;

char s[10];
const int maxn = 10000;
int a, b, n;
vector <int> g[2][maxn];
bool marked[maxn];

void dfs(int v, int fl) {
	marked[v] = true;

	for (size_t i = 0; i < g[fl][v].size(); i++) 
		dfs(g[fl][v][i], fl);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	scanf("%d", &n);

   	while (scanf("\n%s", s) == 1 && s[0] != 'B') {
   	    sscanf(s,"%d", &a);
   	    scanf("%d", &b);
   		g[0][a].push_back(b);
   		g[1][b].push_back(a);
   	}

   	while (scanf("%d", &a) == 1) {
   		dfs(a, 1);
   		dfs(a, 0);
   	}

   	bool flag = false;

   	for (int i = 1; i <= n; i++) {
   		if (!marked[i]) {
   			printf("%d ", i);
   			flag = true;
   		}
   	}

   	if (!flag)
   		printf("%d", (int)flag);

   	return 0;	
}
