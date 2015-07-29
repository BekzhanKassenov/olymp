#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

const int MAXN = 40010;

vector <int> g[MAXN];

vector <PII> zapr[MAXN];

vector <int> ans;

bool used[MAXN];

vector <PII> q;

void dfs(int v)
{
	used[v] = true;

	//cout << v << endl;

	for (size_t i = 0; i < zapr[v].size(); i++)
		{
			int to  = zapr[v][i].F;
			int ind = zapr[v][i].S;

			if (used[to]) 
				if (q[ind].F == to)
					ans[ind] = 1;
				else
					if (q[ind].S == to)
						ans[ind] = 2;	
		}

	for (size_t i = 0; i < g[v].size(); i++)
		dfs(g[v][i]);

	used[v] = false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	int x, y;

	int beg = -1;

	for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);

			if (y == -1)
				{
					beg = x;
					continue;
				}

			g[y].push_back(x);
		}

	int m;

	scanf("%d", &m);

	q.resize(m);

	ans.resize(m);

	for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &q[i].F, &q[i].S);
			zapr[q[i].F].push_back(MP(q[i].S, i));
			zapr[q[i].S].push_back(MP(q[i].F, i));
		}

	dfs(beg);

	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);

	return 0;
}
