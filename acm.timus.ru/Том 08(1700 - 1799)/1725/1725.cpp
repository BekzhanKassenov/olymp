#include <stdio.h>

int main() {
	int n, k;

	scanf("%d%d", &n, &k);

	int ans = k - 3;

	int tmp = n - k + 1; 

	if (tmp - 3 > ans)
		ans = tmp - 3;

	k = tmp < k ? tmp : k;

	printf("%d", (ans > (n / 2 - k)) ? ans : (n / 2 - k));
}
