#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxn = 100010;

int a[maxn], color[maxn];
int n, t, cnt = 0;

bool dfs(int v) {
	if (v == 0)
		return true;

	color[v] = 1;

	if (color[a[v]] == 1)
		return false;

	bool flag = true;

	if (color[a[v]] == 0)
		flag &= dfs(a[v]);

	color[v] = 2;

	return flag;
}

int main() {
 	#ifndef ONLINE_JUDGE
 		freopen("in", "r", stdin);
 	#endif

 	scanf("%d", &t);

 	while (t--) {
 		scanf("%d", &n);
 		
 		cnt = 0;
 		for (int i = 1; i <= n; i++) {
 			scanf("%d", &a[i]);
 			cnt += (a[i] == 0);
 		}

 		if (!cnt || cnt > 1) {
 			puts("NO");
 			continue;
 		}

 		bool flag = false;

 		for (int i = 1; i <= n; i++)
 			if (!color[i] && !dfs(i))
 			 	flag = true;

 		puts(flag ? "NO" : "YES");

 		memset(color, 0, sizeof color);
 	}

 	return 0;
}