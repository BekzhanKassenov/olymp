#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> clr;

struct edge
{
	int from, to, cost;
};

bool operator < (const edge& a, const edge& b)
{
	if (a.cost < b.cost)
		return true;

	return false;
}

int get_clr(int v)
{
	if (clr[v] == v)
		return v;
	else
		return clr[v] = get_clr(clr[v]);
}

bool un(int a, int b)
{
	int ca = get_clr(a);

	int cb = get_clr(b);

	if (ca == cb)
		return false;

	clr[ca] = cb;

	return true;
}

int main()
{
	int n, m;

	cin >> n >> m;

	vector <edge> g(m);

	clr.resize(n);

	for (int i = 0; i < n; i++)
		clr[i] = i;

	for (int i = 0; i < m; i++)
		{
			cin >> g[i].from >> g[i].to >> g[i].cost;
			g[i].from--; 
			g[i].to--;
		}

  	sort(g.begin(), g.end());

  	int ans = 0;

  	for (int i = 0; i < m; i++)
  		{
  			if (un(g[i].from, g[i].to))
  				ans += g[i].cost;
  		}

  	cout << ans;
  	return 0;
}

