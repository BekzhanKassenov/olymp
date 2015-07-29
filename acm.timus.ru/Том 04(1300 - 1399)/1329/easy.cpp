#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 40010;

int tin[MAXN], tout[MAXN];

vector <int> g[MAXN];

int timer = 0;

void dfs(int v)
{
	tin[v] = timer++;

	for (size_t i = 0; i < g[v].size(); i++)
		dfs(g[v][i]);

	tout[v] = timer++;
}

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	int a, b;

	int pr = -1;

	for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &b);

			if (b == -1)
				pr = a;
			else
				g[b].push_back(a);	
		}

	dfs(pr);

	int m;

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);

			if (tin[a] < tin[b] && tout[a] > tout[b])
				puts("1");
			else
				{
					if (tin[b] < tin[a] && tout[b] > tout[a])
						puts("2");
					else
						puts("0");	
				}
		}

	return 0;	
}
