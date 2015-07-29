#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	int used[100010];
	int z;
	for (int i=0;i<100010;i++)
			used[i]=0;
	for (int i=0;i<n;i++)
		{
			cin>>z;
			used[z]=1;
		}
	for (int i=0;i<m;i++)
		{
			cin>>z;
			if (used[z]==1)
			used[z]=2;
		}
	for (int i=0;i<100010;i++)
		if (used[i]==2) cout<<i<<" ";
	return 0;
}
