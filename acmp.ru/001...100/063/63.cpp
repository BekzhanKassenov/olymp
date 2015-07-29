#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int a,b;
	cin>>a>>b;
	int k=int(sqrt(double(b)));
	for (int i=1;i<=k;i++)
		if (b%i==0)
			if (i+b/i==a)
				{
					cout<<i<<" "<<b/i;
					return 0;
				}
}
