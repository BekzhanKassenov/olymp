#include <cstdio>

using namespace std;

int v[800][800], a[800][800];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	
	int mn;

	for (int i = 0; i < n; i++)
		{
			mn = 0;
			for (int j = 0; j < m; j++)
				if (a[i][j] < a[i][mn])
					mn = j;
			for (int j = 0; j < m; j++)
				if (a[i][mn] == a[i][j])
					v[i][j] = true;
		}

	int ans = 0;
	
	for (int j = 0; j < m; j++)
		{
			mn = 0;
			for (int i = 0; i < n; i++)
				if (a[i][j] > a[mn][j])
					mn = i;
			for (int i = 0; i < n; i++)
				if (a[mn][j] == a[i][j] && v[i][j])
					ans++;
		}

	
	printf("%d", ans);
	return 0;
}
