#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, k, a[10010];

bool calced[10010];

int calc(int cur_budget, int ask) {
	if (ask > cur_budget)
		return m;

	cur_budget -= ask;
	
	if (calced[cur_budget])
		return a[cur_budget];

	calced[cur_budget] = true;

	for (int i = 1; i <= k; i++) {
		int tmp = calc(cur_budget, i);


	}

	return a[cur_budget];
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d%d", &n, &m, &k);

	printf("%d %d", calc(n, 0), calc(n - calc(n, 0), 0));

}
