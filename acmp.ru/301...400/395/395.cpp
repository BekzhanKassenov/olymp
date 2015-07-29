#include <iostream>
#include <cstdio>

using namespace std;

int prv(int n)
{
	int c=n;
	int ans=1;
	while (c>0)
		{
			ans*=c%10;
			c/=10;
		}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int l,r;
	cin>>l>>r;
	int ans=0;
	for (int i=l;i<=r;i++)
		{
			int k=prv(i);
			if (k!=0 && i%k==0) ans++;
		}
	cout<<ans;
	return 0;
}
