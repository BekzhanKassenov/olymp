#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n;
	
	int w, h;
	
	cin >> w >> h;
	
	cin >> n;
	
	bool a[105][105];
	
	for (int i = 0; i <= w + 1; i++)
		for (int j = 0; j <= h + 1; j++)
			a[i][j]=false;

	int x1, y1, x2, y2;

	for (int i=0;i<n;i++)
		{
			cin>>x1>>y1>>x2>>y2;
				for (int i=x1+1;i<=x2;i++)
					{
						for (int j=y1+1;j<=y2;j++)
							a[i][j]=true;
					}
		}
	int ans=0;
	for (int i=1;i<=w;i++)
		for (int j=1;j<=h;j++)
			ans+=1-int(a[i][j]);
	cout<<ans;
	return 0;
}
