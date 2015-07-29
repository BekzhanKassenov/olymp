#include <iostream>
#include <cstdio>

using namespace std;

bool clr[1001];
int a[1001][1001];
int n,m,s,t;
int maxs;
int path [1001];
int st[1001];
int sc=0;
int sc1;

void dfs(int z,int k)
{
if (z!=t)
for (int i=0;i<n;i++)
{
if ((a[z][i]!=0) && (!clr[i])) 
{
	clr[i]=true;
	st[sc]=i;
	sc++;
	if ((a[z][i]<k) || (k==0))
		  dfs(i,a[z][i]);
	else dfs(i,k);
	clr[i]=false;
	sc--;
}
else
if (k>maxs) 
{
for (int i=0;i<sc;i++)
path[i]=st[i];
sc1=sc;
maxs=k;
}
}
}


int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	for (int i=0;i<1001;i++)
	clr[i]=false;
	int x,y,z;
	bool lg=false;
	cin>>n>>m>>s>>t;
	for (int i=0;i<m;i++)
		{
			cin>>x>>y>>z;
			a[x][y]=z;
			a[y][x]=z;
			if ((x==t)|| (y==t)) lg=true;
		} 
	if (!lg) 
		{
			cout<<"Np path!";
			return 0;
		} 
	dfs(s,0);
	cout<<maxs<<endl<<sc1<<endl;
	for (int i=0;i<=sc1;i++)
	cout<<path[i]<< " ";
	return 0;
}
