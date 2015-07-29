#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100010; // 10^5 + 10

int t[MAXN]; // Fenwick tree
int a[MAXN]; // Array itself

int n, m;
int type, pos, x, l, r;

void update(int pos, int val) {
	for (int i = pos; i < n; i |= (i + 1))
		t[i] += val;
}

int sum(int pos) {
 	if (pos < 0)
 		return 0;

 	int result = 0;
	for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
	 	result += t[i];
	}

	return result;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &a[i]);
	 	update(i, a[i]);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
	 	scanf("%d", &type);

	 	if (type == 0) { // update
	 	 	scanf("%d%d", &pos, &x);
	 	 	update(pos, x - a[pos]);  // a[pos] += x - a[pos]
	 	 	a[pos] = x;
	 	} else {
	 		scanf("%d%d", &l, &r);
	 		printf("%d\n", sum(r) - sum(l - 1));
	 	}
	}

	return 0;
}
