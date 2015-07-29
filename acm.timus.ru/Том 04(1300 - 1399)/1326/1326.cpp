#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

const int maxn = 21;
const int maxm = 510;
const int INF = INT_MAX;

int cost[maxn], n, m, x, k, masks[maxm], dp[1 << maxn], costmask[maxm], resmask, ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    	scanf("%d", &cost[i]);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
    	scanf("%d", &costmask[i]);

    	scanf("%d", &k);

    	for (int j = 0; j < k; j++) {
    		scanf("%d", &x);
    		masks[i] |= (1 << (x - 1));
    	}
    }

    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
    	scanf("%d", &x);
    	resmask |= (1 << (x - 1));
    	ans += cost[x - 1];
	}

	for (int mask = 1; mask < (1 << n); mask++) {
	    for (int j = 0; j < n; j++) {
    		if (mask & (1 << j))
    			dp[mask] += cost[j];
    	}
	}

    for (int mask = 0; mask < (1 << n); mask++) {
    	for (int j = 0; j < m; j++) {
    		dp[mask | masks[j]] = min(dp[mask | masks[j]], dp[mask] + costmask[j]);
    	}

    	if ((mask & resmask) == resmask)
    		ans = min(ans, dp[mask]);
    }

    printf("%d\n", ans);

	return 0;
}
