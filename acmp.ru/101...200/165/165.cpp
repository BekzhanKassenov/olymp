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
	vector <vector <int> > a(n, vector <int> (m));
	vector <vector <int> > ans(n, vector <int> (m,0));

	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin>>a[i][j];
	
	ans[0][0]=1;
	
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			{
				if (i==n-1 && j==m-1)
					
					break;
				
				if (i+a[i][j]<n)
					
					ans[i+a[i][j]] [j]+=ans[i][j];

				if (j+a[i][j]<m)
					
					ans[i] [j+a[i][j]]+=ans[i][j];
			}
	cout<<ans[n-1][m-1];
	return 0;
}
