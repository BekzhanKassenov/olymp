#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int mx=-999999,mn=999999;
	int z;
	int i=1;
	while (cin>>z)
		{
			if (i%2==0)
				mx=max(mx,z);
			else 
				mn=min(mn,z);
			i++;
		}
	cout<<mx+mn;
	return 0;
}
