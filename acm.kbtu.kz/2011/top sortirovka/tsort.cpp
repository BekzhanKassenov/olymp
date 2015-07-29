#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <bool> >g;
vector <int> top;
vector <bool> used;
int n;
vector <bool> s;

void init()
{
	g.resize(n);
	for (int i=0;i<n;i++)
		g[i].resize(n);
	used.resize(n);
	s.resize(n);
	top.clear();
	for (int i=0;i<n;i++)
		{
			used[i]=false;
			s[i]=false;
			for (int j=0;j<n;j++)
				g[i][j]=false;
		}
	return;
}

void dfs(int v)
{
	used[v]=true;
	for (int i=0;i<n;i++)
		if (!used[i] && g[v][i]) 
				dfs(i);
	top.push_back(v);
}

bool test()
{
	for (int i=0;i<n;i++)
		{
			for (int j=i+1;j<n;j++)
				if (g[i][top[j]]) return false;
		}
	return true;
}

int main()
{
	cin>>n;
	init();
	for (int i=0;i<n;i++)
		{
			int m;
			cin>>m;
			for (int j=0;j<m;j++)
				{
					int z;
					cin>>z;
					g[i][z-1]=true;
					s[z-1]=true;
				}
		}
	for (int i=0;i<n;i++)
		if (!s[i] && !used[i])
			dfs(i);
	if (!test())
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES"<<endl;
	for (int i=0;i<n;i++)
		cout<<top[i]+1<<endl;
	return 0;
}

