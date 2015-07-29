#include <iostream>
#include <cstdio>

using namespace std;

int a[5000], n;

void solve(int l, int r) {
	if (l > r)
		return;

	if (l == r) {
		printf("%d ", a[l]);
		return;
	}

	int pos = l;

	while (pos < r && a[pos] < a[r])
		pos++;

	solve(pos, r - 1);
	solve(l, pos - 1);

	printf("%d ", a[r]);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

   	solve(0, n - 1);

   	return 0;
}
