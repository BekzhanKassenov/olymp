#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	long long prv=1,sum=0;
	while (n>0)
		{
			prv*=(long long) (n%m);
			sum+=(long long) (n%m);
			n/=m;
		}
	cout<<prv-sum;
	return 0;
}
