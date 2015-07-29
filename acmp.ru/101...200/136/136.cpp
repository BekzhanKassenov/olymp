#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int inf=99999999;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <vector <int> > d(n, vector <int> (n));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			{
				int k;
				cin>>k;
				if (k==-1)
					d[i][j]=inf;
				else 
					d[i][j]=k;
			}
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
   int ans=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			{
				if ((i!=j) && (d[i][j]!=inf))
					ans=max(ans,d[i][j]);
			}
	cout<<ans;
	return 0;
}
