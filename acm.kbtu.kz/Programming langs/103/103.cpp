#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct edge
{
	int from;
	int to;
	int val;
};

#define INF 2000000000

int main()
{
	int n, m;
	cin >> n >> m;
	int s, f;
	cin >> s >> f;
	s--, f--;

	vector <edge> a(m);

	int x, y, val;
	for (int i = 0; i < m; i++)
		cin >> a[i].from >> a[i].to >> a[i].val;

	vector <int> d(n, INF);

	d[s] = 0;

	vector <int> pr(n, -1);

	for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m; j++)
				if (d[a[j].from] < INF && d[a[j].from] + a[j].val < d[a[j].to])
					{
						d[a[j].to] = d[a[j].from] + a[j].val;
						pr[a[j].to] = a[j].from;
					}
		}

	cout << d[f] << endl;

	vector <int> ans;

	for (int i = f; i != -1; i = pr[i])
		ans.push_back(i);
	
	for (int i = (int)ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';

	return 0;
}
