#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int z;
	cin>>z;
	for (int t=0;t<z;t++)
		{
			int n,m;
			cin>>n>>m;
			vector <vector <int> > a;
			a.resize(n);
			for (int i=0;i<n;i++)
				a[i].resize(m);
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++)
					cin>>a[i][j];
			bool lg=true;
			for (int i=0;i<n-1;i++)
				{
					for (int j=0;j<m-1;j++)
						{
							if ((a[i][j]==a[i+1][j]) && (a[i][j]==a[i][j+1]) && (a[i][j]==a[i+1][j+1])) 
								{
									cout<<"NO"<<endl;
									lg=false;
									break;
								}
						}
						if (!lg) break;
				}
			if (lg)
				cout<<"YES"<<endl;
		}
	return 0;	
}
