#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	vector <vector <int> > a(n,vector<int> (m,0));
	char c;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			{
				cin>>c;
				if (c=='*') a[i][j]=1;
				else a[i][j]=0;
			}
	int l=-1,r=-1,u=-1,d=-1;
	
	for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
				if (a[j][i]==1)
					{
						l=i;
						break;
					}
			if (l!=-1) break;
		}
	
	for (int i=m-1;i>=0;i--)
		{
			for (int j=0;j<n;j++)
				if (a[j][i]==1)
					{
						r=i;
						break;
					}
			if (r!=-1) break;
		}
	
	for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
				if (a[i][j]==1) 
					{
						u=i;	
						break;
					}
			if (u!=-1) break;
		}
	
	for (int i=n-1;i>=0;i--)
		{
			for (int j=0;j<m;j++)
				if (a[i][j]==1) 
					{
						d=i;	
						break;
					}
			if (d!=-1) break;
		}
	
	for (int i=u;i<=d;i++)
		for (int j=l;j<=r;j++)
			(a[i][j]=1);
	
	for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
				if (a[i][j]==1) cout<<'*';
				else cout<<'.';
			cout<<endl;
		}
				
		return 0;
}
