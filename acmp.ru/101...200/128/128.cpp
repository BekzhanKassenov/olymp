#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int x,y,x1,y1;
vector <vector <int> > a;

bool test(int x,int y)
{
	if (x>0 && x<=n)
		if (y>0 && y<=n) return true;
	return false;
}

void mk(int i, int j, int k)
{
	if (test(i,j))
		{
			if (a[i][j]==-1 || a[i][j]>k+1)
				a[i][j]=k+1;
			if (i==x1 && j==y1)
				{	
					cout<<a[i][j];
					exit(0);
				}
		}

}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	cin>>x>>y>>x1>>y1;
	a.resize(n+1);
	for (int i=0;i<=n;i++)
		a[i].resize(n+1);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			a[i][j]=-1;
	a[x][y]=0;
	for (int k=0;k<n*n;k++)
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (a[i][j]==k)
						{
							mk(i-2,j+1,k);
							mk(i-1,j+2,k);
							mk(i-1,j-2,k);
							mk(i-2,j-1,k);
							mk(i+2,j+1,k);
							mk(i+1,j+2,k);
							mk(i+1,j-2,k);
							mk(i+2,j-1,k);
						}
		}
	return 0;
}
