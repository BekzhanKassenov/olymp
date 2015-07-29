#include <cstdio>

using namespace std;

bool can(int a, int b)
{
	if (a < 0)
		return false;

	int ans = 0;

	for (int i = 1; i * i <= a; i++)
		if (a % i == 0)
			ans++;

	if (ans == b)
		return true;
	return false;
}

int main()
{
	int n, m, k;

	scanf("%d%d%d", &m, &n, &k);

	for (int i = 1; i <= 10000; i++)
		{
			if (can(i, n) && can(i - k, m))
				{
					printf("%d", i);
					return 0;
				}
		}
	printf("0");
	return 0;
}
