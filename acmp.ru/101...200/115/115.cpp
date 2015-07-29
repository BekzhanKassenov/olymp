#include <iostream>
#include <cstdio>

using namespace std;

int a[110][110], sum[110][110], n, m;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

   	for (int i = 1; i <= n; i++)
   		for (int j = 1; j <= m; j++)
   			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];

  	int ans = 0;

   	for (int i = 1; i <= n; i++) {
   		for (int j = 1; j <= m; j++) {
   			for (int k = i; k <= n; k++) {
   				for (int l = j; l <= m; l++) {
   					int s = sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1];
   					ans = max(ans, s); 
   				}
   			}
   		}
   	}

   	printf("%d", ans);

   	return 0;
}
