#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool prost(int n)
{
	if (n==2) return true;
	if (n==1) return false;
	int k=(int)sqrt((double)(n))+1;
	for (int i=2;i<=k;i++)
		if (n%i==0) return false;
	return true;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	int i=1;
	int s=0;
	while (ans!=n)
		{
			i++;
			if (prost(i)) 
				{
					s++;
					if (prost(s)) 
						ans++;
				}
		}
	cout<<i<<" ";
	return 0;
}
