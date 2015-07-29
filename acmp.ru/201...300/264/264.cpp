#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int mx=0;
	int t=0;
	for (int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if (x>0)
				t++;
			else t=0;
			mx=max(mx,t);
		}
	cout<<mx;
	return 0;
}
