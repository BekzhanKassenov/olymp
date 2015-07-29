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
	int k=1;
	vector <vector <int> > a(n+1, vector<int> (n+1,0));
	int m=n;
	int d=1;
	int i=0,j=0;
	while (m>0)
		{
			int z=1;
			while (z<=m)
				{
				   j+=d;
					a[i][j]=k;
					k++;
					z++;
				}
			m--;
			z=1;
			while (z<=m)
				{
					i+=d;
					a[i][j]=k;
					k++;
					z++;
				}
			d*=(-1);
		}
	for (int i=0;i<n;i++)
		{
			for (int j=1;j<=n;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
	   }
   return 0;
}
