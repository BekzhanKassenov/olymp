#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("elections.in","r",stdin);
	freopen("elections.out","w",stdout);
	int n,k;
	bool a[300001];
	cin>>n>>k;
	for (int i=0;i<=n;i++)
		a[i]=false;
	int z,s=n;	
	for (int i=1;i<=k;i++)
		{
			scanf("%d",&z);
			int j=1;
			while ((j*z)<=n)
				{
					if (!a[j*z])
						{
							s--;
							a[j*z]=true;
						}
					j++;
				}
			if (s==1) break;
		}
	cout<<s;
	return 0;
}

