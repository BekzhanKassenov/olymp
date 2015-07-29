#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > g;

set <pair <int, int> > s;

int n, m;

const int INF = (int)2e9;

int prim(bool flag)
{
	vector <bool> used(n, false);

	vector <int> min_e(n, INF), sel_e(n, -1);

	min_e[0] = 0;

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			int v = -1;

			for (int j = 0; j < n; j++)
				if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
					v = j;

			if (min_e[v] == INF)
				return INF;

			used[v] = true;

			if (flag && sel_e[v] != -1)
				{
					s.insert(make_pair(v, sel_e[v]));
				}

			ans += min_e[v];

			for (int j = 0; j < n; j++)
				if (g[v][j] < min_e[j])
					{
						min_e[j] = g[v][j];
						sel_e[j] = v;
					}
		}

 	return ans;
}

void output(int q)
{
	cout << "Cost: ";

	if (q < INF)
		cout << q;	
	else
		cout << -1;

	cout << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	cin >> n >> m;

	g.resize(n, vector <int> (n, INF));

	int a, b, c;

	for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;

			a--, b--;

			g[a][b] = g[b][a] = c;
	   	}

	int k = prim(true);

	int ans = INF;

	for (set <pair <int, int> > :: iterator it = s.begin(); it != s.end(); it++)	
		{
			int a = it -> first, b = it -> second;

			int tmp = g[a][b];

			g[a][b] = g[b][a] = INF;

			ans = min(ans, prim(false)); 

			g[a][b] = g[b][a] = tmp;
		}	                                
		    
	output(k);

	output(ans);

	return 0;
}
                                      