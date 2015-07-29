#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > g;

int n;

vector <bool> used;

vector <int> color;

void init()
{
	used.assign(n,false);
	color.assign(n, false);
	g.assign(n, vector <int> (n));
}

void read()
{
	int x;
	for (int i = 0; i < n; i++)
		{
			while (cin >> x && x != 0)
				{
        			g[i][--x] = 1;
        			g[x][i] = 1;
        		}
		}	
}

bool dfs(int v, int col)
{
	used[v] = true;
	color[v] = col;
	bool ans = true;
	for (int i = 0; i < n; i++)
		{
			if (!g[v][i])
				continue;
			if (!used[i])
				ans &= dfs(i, 3 - col);
			else
				if (color[v] == color[i])
					return false;
		}
	return ans;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;
	
	init();
	
	read();
	
	for (int i = 0; i < n; i++)
		if (!used[i])
			{
				bool b = dfs(i, 2);
				if (!b)
					{
						cout << -1;
						return 0;
            	}
			}
	
	for (int i = 0; i < n; i++)
		cout << color[i] % 2;
	
	return 0;
}
