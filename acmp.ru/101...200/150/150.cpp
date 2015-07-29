#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > a;
vector <bool> used;

int n;

void dfs (int v)
{
	used[v]=true;
	for (int i=0;i<n;i++)
		if (!used[i] && a[v][i]==1)
			dfs(i);
}

int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int s;
	cin>>n>>s;
	a.resize(n);
	for (int i=0;i<n;i++)
		a[i].resize(n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>a[i][j];
	used.resize(n);
	for (int i=0;i<n;i++)
		used[i]=false;
	dfs(s-1);
	int ans=0;
	for (int i=0;i<n;i++)
		if (used[i])
			ans++;
	cout<<ans-1;
	return 0;
}
