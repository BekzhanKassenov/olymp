#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int a[210];
	for (int i=0;i<210;i++)
	a[i]=0;
	int k;
	for (int i=0;i<n;i++)
	{
		cin>>k;
		a[k+100]++;
	}
	for (int i=0;i<210;i++)
	{
		for (int j=1;j<=a[i];j++)
		cout<<i-100<<" ";
	}
	return 0;
}
