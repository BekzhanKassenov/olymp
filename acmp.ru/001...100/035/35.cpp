#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int k;
	cin>>k;
	long long m,n;
	for (int i=1;i<=k;i++)
		{
			cin>>n>>m;
			cout<<(19*m+((n+239)*(n+366))/2)<<endl;
		}
	return 0;
}
