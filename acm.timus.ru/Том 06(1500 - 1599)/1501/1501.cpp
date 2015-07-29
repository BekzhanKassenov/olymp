#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

bool a[1010], b[1010], used[1010][1010];

int cnt[2];

bool calc(int aa, int bb) {
	if (used[aa][bb])
		return false;

	used[aa][bb] = true;

	if (aa == 0 && bb == 0)
		return true;

	if (aa == 0) {
		cnt[b[bb]]++;

		if (abs(cnt[0] - cnt[1]) > 1) {
			cnt[b[bb]]--;
			return false;
		}

		if (calc(aa, bb - 1)) {
			putchar('2');
			return true;
		}

		cnt[b[bb]]--;

		return false;	
	}

	if (bb == 0) {
		cnt[a[aa]]++;

		if (abs(cnt[0] - cnt[1]) > 1) {
			cnt[a[aa]]--;
			return false;
		}

		if (calc(aa - 1, bb)) {
			putchar('1');
			return true;
		}

		cnt[a[aa]]--;

		return false;	
	}

	cnt[a[aa]]++;

	if (abs(cnt[0] - cnt[1]) <= 1) {
		if (calc(aa - 1, bb)) {
			putchar('1');
			return true;
		}
	}

	cnt[a[aa]]--;

	cnt[b[bb]]++;

	if (abs(cnt[0] - cnt[1]) <= 1) {
		if (calc(aa, bb - 1)) {
			putchar('2');
			return true;
		}
	}

	cnt[b[bb]]--;

	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	getchar();

	for (int i = 1; i <= n; i++) 
		a[i] = (getchar() - '0');

	getchar();

	for (int i = 1; i <= n; i++)
		b[i] = (getchar() - '0');

   	if (!calc(n, n))
   		puts("Impossible");

	return 0;	
}
