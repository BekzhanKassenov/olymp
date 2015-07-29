#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

long long sc(long long n)
	{
		int s=0;
		while (n>0)
			{
				s+=n%10;
				n=n/10;
			}
		return s;
	}

long long sum(long long x)
	{	
		long long s=0;
		long long z=(long long)(sqrt(x));
		for (long long i=1;i<=z;i++)
			if ((x % i) ==0) 
				{
					s+=sc(i*i);
					if ((i*i)!=x)
					s+=sc((x/i)*(x/i));
				}
		return s;
	}


int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	long long x;
	cin>>x;
	if (x==1)
		{
			cout<<"0 1";
			return 0;
		}
	set<long long> nmb;
	nmb.insert(20);
	nmb.insert(24);
	nmb.insert(67);
	nmb.insert(26);
	nmb.insert(40);
	nmb.insert(17);
	nmb.insert(41);
	long long a;

	for (int i=1;i<=1000;i++)
		{
			a=sum(x);
			if (nmb.find(a)!=nmb.end())
				{
					cout<<i<<" "<<7;
					return 0;
				} 
			x=a;
		}
	cout<<"-1 -1";
	return 0;
}
