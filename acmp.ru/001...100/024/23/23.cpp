#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int rnd(double n)
{
	int k=(int) n;
	double c=(double(k)+double(k+1))/2;
	if (n>=c) return k+1;
	return k;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int k=int(rnd(sqrt(double(n))));
	int ans=0;
	for (int i=1;i<=k;i++)
		{
			if ((n%i)==0)
				{
					if (n/i!=i)
					ans+=n/i;
					ans+=i;
				}
		}
	cout<<ans;
	return 0;
}
