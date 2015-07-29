#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

#define PII pair <int, int>
#define x first
#define y second
#define sqr(x) (x) * (x)

PII a[1000];

int ans, ans_x, ans_y, n;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	ans_x = 10000, ans_y = 10000;

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		if (ans_y > a[i].y || ans_y == 10000) {
			ans_x = a[i].x;
			ans_y = a[i].y;
		}
	}
	ans_y--;

	ans = 0;

	for (int i = 0; i < n; i++) {
		ans = max(ans, sqr(a[i].x - ans_x) + sqr(a[i].y - ans_y));
	}

	printf("%d %d %.10lf", ans_x, ans_y, sqrt(ans));

	return 0;
}
