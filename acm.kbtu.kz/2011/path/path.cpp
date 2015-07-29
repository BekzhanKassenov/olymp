#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int n,m;
	int ms;
	bool gr[1001][1001];
	int t,j,f;
	cin>>n>>m;
	cin>>ms;
	for (int i=0;i<m;i++)
		{
			cin>>t>>j>>f;
			if (f>=ms)
				{
					gr[t][j]=true;
					gr[j][t]=true;
				}
		}
	
	bool used [1001];
	int och[1001];
	t=1;
	j=2;
	for (int i=1;i<=n;i++)
			used[i]=false;

	used[1]=true;
	och[1]=1;
	while (t<=j)
		{
			f=och[t];
			t++;
			for (int i=1;i<=n;i++)
				{
					if ((gr[f][i]) && (used[i]==false))
						{
							och[j]=i;
							used[i]=true;
							j++;
						}	
				}
		}
	if (used[n]) 
		cout<<"YES";
	else 
		cout<<"NO";
	return 0;
}
