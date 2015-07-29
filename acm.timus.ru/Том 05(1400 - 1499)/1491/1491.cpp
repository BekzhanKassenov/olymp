#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100010;

int t[maxn], flag[10 * maxn];

int n;

void push(int v, int l, int r) {
	if (l == r) {
		t[l] += flag[v];
		flag[v] = 0;
	} else 
		if (l < r) {
			flag[v << 1] += flag[v];
			flag[(v << 1) + 1] += flag[v];
			flag[v] = 0;
		}
}

void upd(int v, int l, int r, int zl, int zr, int val) {
	push(v, l, r);

	if (l > r || zl > r || zr < l)
		return;

	if (l >= zl && r <= zr) 
	 	flag[v] += val;
	else {
		int m = (l + r) >> 1;

		upd(v << 1, l, m, zl, zr, val);
		upd((v << 1) + 1, m + 1, r, zl, zr, val);
	}
}

int rd(int pos) {
	int v = 1, l = 0, r = n - 1;

	while (l < r) {
		push(v, l, r);

		int m = (l + r) >> 1;

		v <<= 1;

		if (pos > m) {
			l = m + 1;
			v++;
		} else 
		 	r = m;
	}

	push(v, l, r);

	return t[l];
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	int a, b, c;

	for (int i = 0; i < n + 1; i++) {
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;

		upd(1, 0, n - 1, a, b, c);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", rd(i));

   	return 0;
}
