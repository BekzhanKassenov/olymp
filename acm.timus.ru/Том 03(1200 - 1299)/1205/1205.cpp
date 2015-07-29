#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

#define sqr(x) (x) * (x)
#define F first
#define S second
#define MP make_pair

double dist(double x, double y, double xz, double yz, double v)
{
	return (sqrt(sqr(xz - x) + sqr(yz - y)) / v);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	double v1, v2;

	scanf("%lf%lf", &v1, &v2);

	int n;

	scanf("%d", &n);

	n += 2;

	int s = n - 1;

	vector <pair <double, double> > arr(n);

	for (int i = 0; i < s - 1; i++)
		scanf("%lf%lf", &arr[i].F, &arr[i].S);

	vector <vector <double> > g(n, vector <double>(n, -1));

	vector <bool> used(n, 0);

	int a, b;

	scanf("%d%d", &a, &b);

	while (a != 0 || b != 0)
		{
			a--, b--;

			g[b][a] = g[a][b] = dist(arr[a].F, arr[a].S, arr[b].F, arr[b].S, v2);

			scanf("%d%d", &a, &b);
		}

  	scanf("%lf%lf%lf%lf", &arr[n - 2].F, &arr[n - 2].S, &arr[n - 1].F, &arr[n - 1].S);

  	for (int i = 0; i < n; i++)
  		for (int j = i; j < n; j++)
  			if (g[i][j] == -1)
  				g[i][j] = g[j][i] = dist(arr[i].F, arr[i].S, arr[j].F, arr[j].S, v1);
  	
  	const double INF = 2e+9;
  	vector <double> d(n, INF);

  	vector <int> pr(n, -1);

  	d[n - 2] = 0;

  	for (int i = 0; i < n; i++)
  		{
  			int v = -1;

  			for (int j = 0; j < n; j++)
  				if (!used[j] && (v == -1 || d[j] < d[v]))
  					v = j;

  		  	used[v] = true;

  		  	for (int j = 0; j < n; j++)
  		  		if (d[j] > d[v] + g[v][j])
  		  			{
  		  				d[j] = d[v] + g[v][j];
  		  				pr[j] = v;
  		  			}
  		}

  	vector <int> ans;

  	printf("%.6lf\n", d[n - 1]);

  	for (int i = pr[n - 1]; i != -1; i = pr[i])
  		ans.push_back(i);

  	printf("%d ", (int)ans.size() - 1);

  	for (int i = ans.size() - 2; i >= 0; i--)	
  		printf("%d ", ans[i] + 1);

  	return 0;
  	
}
