#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int k;

	scanf("%d", &k);

	int n, a;

	while (k--)
		{
			scanf("%d%d", &a, &n);

			a %= n;

			int q = (int)sqrt(double(a));

			bool flag = false;

			for (;q < n; q = (int)sqrt(double(a)))
				{
					if (q * q == a)
						{
							printf("%d ", q);
							flag = true; 
						}
					a += n;
				}
			if (!flag)
				printf("No root");

			printf("\n");
		}

  	return 0;
}
