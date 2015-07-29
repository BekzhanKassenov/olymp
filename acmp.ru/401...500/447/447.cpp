#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	long long ans=1;
	cin>>n;
	for (int i=1;i<=n;i++)
		{
			ans*=(long long)(i);
			while (ans%10==0)
				ans/=10;
			ans%=1000000;
		}
	while (ans%10==0)
		ans/=10;
	cout<<ans%10;
	return 0;
}
