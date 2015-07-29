#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	while (n>0)
		{
			ans+=n%2;
			n=n/2;
		}
	cout<<ans;
}
