/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>


using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 2000000000
#define EPS 10e-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define LL long long
#define ULL unsigned long long
#define int long long

struct edge 
{
	int to;
	int cost;
};

edge make_edge(int a, int b)
{
	edge ans;
	ans.to = a;
	ans.cost = b;
	return ans;
}

vector <int> d;

main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int n, m;

	scanf("%I64d%I64d", &n, &m);

	vector <vector <edge> > g (n);

	int a, b, c;

	for (int i = 0; i < m; i++)
		{
			scanf("%I64d%I64d%I64D", &a, &b, &c);
			g[--a].PB(make_edge(--b, c));
			g[b].PB(make_edge(a, c));
		}

	vector <vector <int> > k(n);

	for (int i = 0; i < n; i++)
		{
			int z;
			scanf("%I64d", &z);
			k[i].resize(z);
			for (int j = 0; j < z; j++)
				scanf("%I64d", &k[i][j]);
		}

	set <PII> p;

	d.assign(n, INF);

	d[0] = 0;

	p.insert(MP(0,0));

	while (!p.empty())
		{
		   int v = p.begin() -> second;
		   p.erase(p.begin());

		   vector <int> :: const_iterator it(lower_bound(k[v].begin(), k[v].end(), d[v]));

		   if (v != n - 1)
		   
		   while (it != k[v].end() && *it == d[v])
		   	{
		   		it++;
		   		d[v]++;
		   	}
			for (size_t j = 0; j < g[v].size(); j++)
				{
					int len = g[v][j].cost;
					int t = g[v][j].to;

					int z = d[v];
					
					z += len;

					if (d[t] > z)
						{
							p.erase(MP(d[t],t));
							d[t] = z;
							p.insert(MP(d[t],t));
						}
					
				}
		}
	if (d[n - 1] != INF)
		printf("%I64d",d[n - 1]);
	else
		puts("-1");
}
