#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	if (m>n)
		{
			cout<<0;
			return 0;
		}
	if (m==n)
		{
			cout<<1;
			return 0;
		}
	if (m==1)
		{
			cout<<n;
			return 0;
		}	
	if (m==0)
		{
			cout<<1;
			return 0;
		}
	long long ans=0;
	int k=m;
	while (k<=n)
		{
			ans+=(long long)(n-k+1);
			k+=m-1;
		}
	cout<<ans;
	return 0;
}
