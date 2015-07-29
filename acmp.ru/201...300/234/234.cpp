#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector <vector <int> > a(n+3, vector <int> (m+3,-1));
	int x,y;
	for (int i=0;i<k;i++)
		{
			cin>>x>>y;
			a[x][y]=0;
		}
	for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				{
					int c=0;
					if (a[i][j]==-1)
						{
							if (a[i-1][j-1]==0)
								c++;
							if (a[i-1][j]==0)
								c++;
							if (a[i-1][j+1]==0)
								c++;
							if (a[i][j-1]==0)
								c++;
							if (a[i+1][j+1]==0)
								c++;
							if (a[i+1][j]==0)
								c++;
							if (a[i+1][j-1]==0)
				            c++;
				         if (a[i][j+1]==0)
				         	c++;
				       }
				  if (c!=0)
				  a[i][j]=c;
				}
	 	}
  	for (int i=1;i<=n;i++)
  		{
  			for (int j=1;j<=m;j++)
  				{
  					if (a[i][j]==0)
  						{
  							cout<<'*';
  							continue;
  				  		}
  					if (a[i][j]==-1)
  						cout<<'.';
  					else cout<<a[i][j];
  			   }
  			cout<<endl;
  		}
  	return 0;
}
