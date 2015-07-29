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


bool prost(int n)
{
	int k=rnd(sqrt(double(n)));
	for (int i=2;i<=k;i++)
		if ((n%i)==0) return false;
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for (int i=n+1;i<2*n;i++)
		{
			if (prost(i)) 
			{
				ans++;
		   }
		}
	cout<<ans;
	return 0;
}
