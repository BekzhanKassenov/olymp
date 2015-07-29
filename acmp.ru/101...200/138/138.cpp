#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int inf = 30000;

struct edge
{
	int from;
	int to; 
	int cost;
};

int main()
{
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);
	int n, m;
	cin >> n >> m;
	vector <edge> g(m);
	int x,y,val;
	for (int i = 0; i < m; i++)
		{	
			cin >> x >> y >> val;
		   g[i].from = --x;
		   g[i].to = --y;
		   g[i].cost = val;
		}
	vector <int> d(n, inf);
	d[0] = 0;
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (d[g[j].from] < inf)
					d[g[j].to] = min(d[g[j].to], d[g[j].from] + g[j].cost);
		}	
	for (int i = 0; i < n; i++)
		cout << d[i] << ' ';
	return 0;	
}
