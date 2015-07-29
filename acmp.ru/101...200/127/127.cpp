#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <vector <int> > a(n, vector <int> (n,0));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>a[i][j];
	const int inf=9999;
	vector <int> dist(n,inf);
	vector <bool> used(n,false);
	int s,f;
	cin>>s>>f;
	dist[s-1]=0;
	for (int i=0;i<n;i++)
		{
			int v=-1;
			for (int j=0;j<n;j++)
				if (!used[j] && (v==-1 || dist[j]<dist[v]))
					v=j;
		  	used[v]=true;
			for (int j=0;j<n;j++)
				if (a[v][j]==1)
					dist[j]=min(dist[j],dist[v]+1);
		}
	if (dist[f-1]!=inf)
		cout<<dist[f-1];
	else cout<<-1;
	return 0;
}
