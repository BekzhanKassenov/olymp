#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long n;
vector <long long> a;

long long sm(long long z)
{
	long long sum=0;
	for (long long i=0;i<n;i++)
		if ((z & (1 << i)) != 0)  sum+=a[i];
	return sum; 
}

long long absm(long long n)
{
	if (n < 0) return -n;
	return n;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	long long sum=0;
	a.resize(n);
	for (long long i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
   long long mn=9999999;
   long long m;
	for (long long i=0;i < (1 << n); i++)
		{
			m=absm(2*sm(i)-sum);
			if (m<mn) mn=m;	
		}
	cout<<mn;
	return 0;
}
