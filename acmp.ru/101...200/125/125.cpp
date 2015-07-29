#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int a[101][101];
	int b[101];
	int ans;
	for (int i=0; i<n;i++)
		{
			for (int j=0;j<n;j++)
				cin>>a[i][j];
		}
	for (int i=0;i<n;i++)
		cin>>b[i];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if ((a[i][j]==1) && (b[i]!=b[j])) ans++;
	cout<<ans/2;
	return 0;
}
