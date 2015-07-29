#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=n;
	n%=10;
	while (m!=1)
		{
			n*=a;
			n%=10;
			m--;
		}
	cout<<n;
	return 0;
}
