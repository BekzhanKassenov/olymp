#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int nmb=-1,mx=0;
	int x,y;
	for (int i=1;i<=n;i++)
		{
			cin>>x>>y;
			if (y==1)
				{
					if (x>mx) 
						{
							mx=x;
							nmb=i;
						}
				}
		}
	cout<<nmb;
	return 0;
}
