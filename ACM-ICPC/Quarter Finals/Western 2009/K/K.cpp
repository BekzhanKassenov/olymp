#include <cstdio>

main() {
	freopen("kids.in", "r", stdin);
	freopen("kids.out", "w", stdout);

	double res = 1.0, n, m;

	scanf("%lf%lf", &n, &m);

	for (m -= 2; m-- >= 0; res = 1.0 + ((n - 1.0) / (n + .0)) * res);

	printf("%.9lf", res);
}
