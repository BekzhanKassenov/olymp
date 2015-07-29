#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int best(int a, int b)
{
	int s1=0, s2=0;
	int k1=a, k2=b;
	while (k1>0) 
	{
		s1+=k1%10;
		k1/=10;
	}
	while (k2>0)
	{
		s2+=k2%10;
		k2/=10;
	}
	if (s1>s2) return a;
	if (s1<s2) return b;
	if (s1==s2) return (min(a,b));
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int k=int(sqrt(double(n)));
	int ans=1;
	for (int i=1;i<=k;i++)
		{
			if ((n%i)==0)
				{
					ans=best(ans,i);
					if (i!=n/i)
					ans=best(ans,n/i);
				}
		}
   cout<<ans;
	return 0;
}
