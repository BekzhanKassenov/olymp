#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	if (a==b) return a;
	if (a>b) return gcd(a-b,b);
	if (a<b) return gcd(b-a,a);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	n=gcd(n,m);
	for (m=1;m<=n;m++)
	cout<<1;
	return 0;
}
