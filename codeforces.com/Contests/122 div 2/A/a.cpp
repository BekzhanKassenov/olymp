#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int ans = 500;
	for (int x=0;x<=n;x++)
		for (int y=0;y<=n;y++)
			for (int z=0;z<=n;z++)
				if (((k-5*x-4*y-3*z)%2==0) && (n-x-y-z>=0) && (n-x-y-z==(k-5*x-4*y-3*z)/2))
					ans=min(ans,n-x-y-z);
	cout<<ans;
	return 0;
}
