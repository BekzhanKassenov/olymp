#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll inf = (((long long)1) << 63) - 1;

struct edge
{
	int from;
	int to;
	ll cost;
};

int main()
{
	freopen("in","r",stdin);
	int n, m, s;
	cin >> n >> m >> s;
	s--;
	vector <edge> g(m);
	for (int i = 0; i < m; i++)
		{
			cin >> g[i].from >> g[i].to >> g[i].cost;
			g[i].from--;
			g[i].to--;
		}
	vector <ll> d(n, inf);
	d[s] = 0;
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (d[g[j].from] < inf)
					if (d[g[j].to] > d[g[j].from] + g[j].cost)
						d[g[j].to] =  d[g[j].from] + g[j].cost;
		}
	
	vector <ll> d1 = d;
	for (int j = 0; j < m; j++)
		if (d[g[j].from] < inf)
			if (d[g[j].to] > d[g[j].from] + g[j].cost)
				d[g[j].to] = d[g[j].from] + g[j].cost;
	
	for (int i = 0; i < n; i++)
		{
			if (d[i] == d1[i] && d[i] != inf)
				cout << d[i] << endl;
			else
				{
					if (d[i] == inf)
						cout << '*' << endl;
					else
						cout << '-' << endl;
				}
		}
	return 0;
}
