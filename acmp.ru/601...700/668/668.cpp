#include <iostream>
#include <cstdio>

using namespace std;

int n, m, ans;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	if (n % 2 == 1 && m == 0) {
	 	puts("-1");
	 	return 0;
	}

	if (m % 2 == 1) {
	 	ans++;
	 	m++;
	}

	if ((m / 2 + n) % 2 == 1) {
	 	ans += 2;
	 	m += 2;
	}

	ans += m / 2;

	ans += (m / 2 + n) / 2;

	printf("%d\n", ans);

	return 0;
}
