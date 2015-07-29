#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int k1,l1,m1,k2,l2,m2;
	cin>>k1>>l1>>m1;
	cin>>k2>>l2>>m2;
	int ans=0;
	ans+=k1*l1/100*m1;
	k1-=k1*l1/100;
	ans+=k2*l2/100*m2;
	k2-=k2*l2/100;
	if (k1>k2)
		ans+=(k1-k2)*m1;
	if (k2>k1)
		ans+=(k2-k1)*m2;
	cout<<ans;
}
