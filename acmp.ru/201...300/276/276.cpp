#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	int k;
	k=n/m;
	int nmb=n-k*m;
	for (int i=1; i<=m-nmb;i++)
		cout<<k<<" ";
	k++;
	for (int i=m-nmb+1;i<=m;i++)
		cout<<k<<" ";
	return 0;
}
