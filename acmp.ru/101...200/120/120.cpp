#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>m>>n;
	int a[20][20];
	for (int i=0;i<m;i++)
	for (int j=0;j<n;j++)
		cin>>a[i][j];
	int b[20][20];
	b[0][0]=a[0][0];

	for (int i=1;i<n;i++)
		b[0][i]=b[0][i-1]+a[0][i];
	for (int i=1;i<m;i++)
		b[i][0]=b[i-1][0]+a[i][0];
	
	for (int i=1;i<m;i++)
		for (int j=1;j<n;j++)
				b[i][j]=min(b[i][j-1],b[i-1][j])+a[i][j];
	cout<<b[m-1][n-1];
	return 0;
}

