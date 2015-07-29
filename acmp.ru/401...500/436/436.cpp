#include <cstdio>

using namespace std;

long long n, base;
int k, ans;

int check(long long num, long long base) {
 	int ans = 0;

 	while (num && num % base == k) {
 	 	ans++;
 	 	num /= base;
 	}

 	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%I64d%d", &n, &k);

	ans = 0;
	base = n + 1;

	if (n <= k) {
	 	printf("%I64d %d\n", base, check(n, base));
	 	return 0;
	}

	long long temp = n - k;
	base = n;
	ans = check(n, base);

	for (long long i = 2; i * i <= temp; i++) {
	 	if (temp % i == 0) {
	 	 	int cnt = check(n, i);
	 	 	if (cnt > ans) {
				ans = cnt;
				base = i;
	 	 	}

	 	 	cnt = check(n, temp / i);
	 	 	if (cnt > ans) {
				ans = cnt;
				base = temp / i;
	 	 	}
	 	}
	}

	printf("%I64d %d\n", base, ans);
	return 0;
}
