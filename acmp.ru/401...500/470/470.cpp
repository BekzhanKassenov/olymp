#include <cstdio>

using namespace std;

int a[110][110], b[110][110], n, m, k;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	b[1][1] = a[1][1];

	for (int i = 2; i <= n; i++)
		b[i][1] = b[i - 1][1] + a[i][1];

	for (int j = 2; j <= m; j++)
		b[1][j] = b[1][j - 1] + a[1][j];

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++)
			b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
	
	int x, y, _x, _y;

	while (k--)
		{
			scanf("%d%d%d%d", &x, &y, &_x, &_y);

			printf("%d\n", b[_x][_y] - b[_x][y - 1] - b[x - 1][_y] + b[x - 1][y - 1]);
		}

	return 0;
}
