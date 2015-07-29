#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int l, r;

	int tmp;

	int m;

	scanf("%d", &m);

	int ans = 0;

	for (int i = 0; i < m; i++)
		{
			scanf("%d", &tmp);

			l = 0, r = n - 1;

			if (l == r)
				{
					if (a[l] == tmp)
						ans++;
					continue;
				}

			while (l <= r)
				{
					int m = (r + l) / 2;

					if (a[m] == tmp || a[l] == tmp || a[r] == tmp)
						{
							ans++;
							break;
						}

					if (tmp < a[m])
						r = m - 1;
					else
						l = m + 1;
				}

		}
	printf("%d", ans);
	return 0;
}
