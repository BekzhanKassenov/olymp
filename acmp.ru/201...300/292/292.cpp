#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool prost (int n)
{
	if (n==1) return false;
	int k=int(sqrt(double(n)));
	for (int i=2;i<=k;i++)
		if (n%i==0) return false;
	return true;
}

int sum(int n)
{
	int c=n;
	int ans=0;
	while (c>0)
		{
			ans+=c%10;
			c/=10;
		}
	return ans;
}

int pck (int n)
{
	if (prost(n)) return n;
	if (n<10 && n>0) return 0;
	return (pck(sum(n)));
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	cout<<pck(n);
	return 0;
}
