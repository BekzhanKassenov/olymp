#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > a;
vector <bool> used; 
int n;

void dfs(int v,int p=-1)
{
	used[v]=true;
	for (int i=0;i<n;i++)
		{
			if (a[i][v]==1 && i!=v)    	
				{
					if (!used[i]) 
						dfs(i,v);
					else
						if (i!=p)	
						{
							cout<<"NO";
							exit(0);
		      		}
		      }
      }
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	int c=0;
	a.resize(n);
	used.resize(n);
	for (int i=0;i<n;i++)
		{	
			used[i]=false;
			a[i].resize(n);
			for (int j=0;j<n;j++)
				{
					cin>>a[i][j];
					if (a[i][j]==1) c++;
				}	
		}
	if (c/2!=n-1)
		{
			cout<<"NO";
			return 0;
		}
	c=0;
	for (int i=0;i<n;i++)
		if (!used[i])
			{
				dfs(i);
				c++;
			}
	if (c>1) 
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
	return 0;
}
