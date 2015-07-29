#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 100001;

vector <int> g[MAXN];

int sz[MAXN];

const int INF = (int)2e9;

bool cmp(int a, int b)
{
	return sz[a] < sz[b];
}

void dfs(int v, int pr = -1)
{
	for (vector <int> :: iterator it = g[v].begin(); it != g[v].end(); it++)
		if (*it == pr)
			{
				g[v].erase(it);
				break;
			}

	for (size_t i = 0; i < g[v].size(); i++)
		dfs(g[v][i], v);

	sort(g[v].rbegin(), g[v].rend(), cmp);

	int t = 1;

	if (g[v].empty())
		{
			sz[v] = 1;
			return;
		}

	for (size_t i = 0; i < g[v].size(); i++)
		{
			sz[v] = max(sz[v], sz[g[v][i]] + t);
			t++;
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		{
			int x;

			while (scanf("%d", &x) && x != 0)
				{
					x--;
					g[i].push_back(x);
					g[x].push_back(i);
				}
		}

	int kor;

	scanf("%d", &kor);

	kor--;

	dfs(kor);

	printf("%d", sz[kor] - 1);

	return 0;
}