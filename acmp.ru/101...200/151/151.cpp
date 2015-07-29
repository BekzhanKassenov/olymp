#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

vector <bool> used;

vector <int> color;

vector <set <int> > g;

int n,m;

void dfs(int v, int c)
{
	used[v]=true;
	color[v]=c;
	for (int i=0;i<n;i++)
		{
			if (!used[i] && g[v].find(i)!=g[v].end()) 
				dfs(i,3-c);
			else
				if ((used[i] && color[i]==c) && g[v].find(i)!=g[v].end())
					{
						cout<<"NO";
						exit(0);
					}

		}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m;
	g.resize(n);
	for (int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			g[x-1].insert(y-1);
			g[y-1].insert(x-1);
		}
	used.resize(n);
	color.resize(n);
	for (int i=0;i<n;i++)
		{
			used[i]=false;
			color[i]=0;
		}
	for (int i=0;i<n;i++)
		if (!used[i]) dfs(i,1);
	cout<<"YES";
	return 0;
}
