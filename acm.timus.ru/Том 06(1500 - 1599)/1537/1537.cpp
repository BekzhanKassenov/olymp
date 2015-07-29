#include <cstdio>

using namespace std;

int dp[(int)1e7 + 10], k, p, i;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	scanf("%d%d", &k, &p);

   	dp[2] = 1 % p;

   	int tmp = k / 2 + 1;

   	for (i = 2; i <= tmp; i++) {
   		dp[i + 1] += dp[i];

   		if (dp[i + 1] >= p)
   			dp[i + 1] -= p;

   		dp[i << 1] += dp[i];

   		if (dp[i << 1] >= p)
   			dp[i << 1] -= p;
   	}

   	for (i++; i <= k; i++) {
   		dp[i] += dp[i - 1];

   		if (dp[i] >= p)
   			dp[i] -= p;
   	}

   	printf("%d", dp[k]);

   	return 0;
}
