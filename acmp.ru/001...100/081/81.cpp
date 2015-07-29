#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int z,mx=0,mn=40000;
	for (int i=1;i<=n;i++)
		{
			cin>>z;
			mx=max(mx,z);
			mn=min(mn,z);
		}
	cout<<mn<<" "<<mx;
}
