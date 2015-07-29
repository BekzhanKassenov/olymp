#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n,k;
vector <vector <int> > g;
vector <bool> used;

void dfs(int v)
{
	used[v]=true;
	if (g[v][k]==1)
		{
			cout << "No";
			exit(0);
		}
	for (int i=0;i<n;i++)
		if (!used[i] && g[v][i]==1)
			dfs(i);
}

void init()
{
	g.resize(n);
	used.resize(n);
	for (int i=0;i<n;i++)
		{
			g[i].resize(n);
			used[i]=false;
			for (int j=0;j<n;j++)
				g[i][j]=0;
		}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> k;
	k--;
	g.resize(n);
	used.resize(n);
	for (int i=0;i<n;i++)
		g[i].resize(n);
   int x,y;
   cin >> x;
   while (x!=0)
   	{	
   		cin >> y;
   		g[x-1][y-1] = 1;
   		cin >> x;
   	}
   dfs (k);
   for (int i=0;i<n;i++)
   	if (!used[i] && i!=k)
   		{
   			cout << "No";
   			return 0;
   		}
   cout << "Yes";
   return 0;
}
