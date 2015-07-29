#include <cstdio>
#include <vector>

using namespace std;

int a[4000010];

int main()
{
	int n;

	scanf("%d", &n);

	int x;

	int point = 0;

	for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);

			if (x == -1)
				{
					printf("%d\n", a[--point]);
				}
			if (x > 0)
				{
					a[point++] = x;
				}
			if (x == 0)
				{
					if (point < n + 10)
						{
							int tmp = point;
							for (int j = 0; j < tmp; j++)
								{
									a[point++] = a[j];
								}	
					   }
				}

		}

 	return 0;
}
