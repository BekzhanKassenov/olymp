#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1 << 16;

int a[MAXN], n, m, x, y, len;
int arr[MAXN];
int sum;

bool check(int a, int b) {
	int c = a ^ b;
	return c > 0 && (c & (c - 1)) == 0;
}

void assign(int pos, int val) {
	pos = (pos + n) & (n - 1);
 	int delta = val - arr[pos];
 	sum += delta;
 	arr[pos] = val;
}

bool check_pos(int pos) {
	pos = (pos + n) & (n - 1);
	int prev = (pos - 1 + n) & (n - 1);
	int next = (pos + 1) & (n - 1);

	return check(a[pos], a[prev]) && check(a[pos], a[next]);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &len);
	n = 1 << len;

	for (int i = 0; i < n; i++) {
	 	scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
	 	assign(i, check_pos(i));
	}

	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		swap(a[x], a[y]);

		for (int i = -1; i <= 1; i++) {
			assign(x + i, check_pos(x + i));
			assign(y + i, check_pos(y + i));
		}

		if (sum == n) {
			puts("Yes");
		} else {
		 	puts("No");
		}
	}

	return 0;
}