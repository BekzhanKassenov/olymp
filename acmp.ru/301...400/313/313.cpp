#include <cstdio>
#include <vector>

using namespace std;

int a[101];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	scanf("%d", &n);

	int ans = 0;

	for (int i = 1; i <= n; i++)
		{
			int tmp;

			scanf("%d", &tmp);

			if (a[tmp] == 0)
				{
					a[tmp] = i;
					continue;
				}

			ans = max(ans, i - a[tmp]);
			a[tmp] = i;
		}

	printf("%d", ans);
	return 0;	
}
