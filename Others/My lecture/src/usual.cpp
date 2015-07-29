#include <cstdio>

using namespace std;

const int MAXN = 100010;

int a[MAXN], sum[4 * MAXN], n, m;
int type, x, pos, l, r;

void build(int v, int l, int r) {
 	if (l == r) {
 	 	sum[v] = a[l];
 	 	return;
 	}

 	int mid = (l + r) / 2;
 	build(2 * v, l, mid);
 	build(2 * v + 1, mid + 1, r);

 	sum[v] = sum[2 * v] + sum[2 * v + 1];
}

void update(int v, int l, int r, int pos, int val) {
 	if (l == r) {
 	 	sum[v] = val;
 	 	return;
 	}

 	int mid = (l + r) / 2;

 	if (pos <= mid)
 		update(2 * v, l, mid, pos, val);
 	else
 		update(2 * v + 1, mid + 1, r, pos, val);

 	sum[v] = sum[2 * v] + sum[2 * v + 1];
}

int get_sum(int v, int l, int r, int ql, int qr) {
 	if (l > r || ql > r || l > qr) {
 	 	return 0;
 	}

 	if (ql <= l && r <= qr) {
 	 	return sum[v];
 	}

 	int mid = (l + r) / 2;
 	
 	return get_sum(2 * v, l, mid, ql, qr) + get_sum(2 * v + 1, mid + 1, r, ql, qr);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &a[i]);
	}

	build(1, 0, n - 1);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
	 	scanf("%d", &type);

	 	if (type == 0) { // update
	 	 	scanf("%d%d", &pos, &x);
	 	 	update(1, 0, n - 1, pos, x);
	 	} else {
	 		scanf("%d%d", &l, &r);
	 		printf("%d\n", get_sum(1, 0, n - 1, l, r));
	 	}
	}

	return 0;
}
