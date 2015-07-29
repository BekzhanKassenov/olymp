#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	vector <int> ans(n,0);
	int a,b;
	for (int i=0;i<m;i++)
		{
			cin>>a>>b;
			ans[a-1]++;
			ans[b-1]++;
		}
	for (int i=0;i<n;i++)
		{
			cout<<ans[i]<<' ';
		}
	return 0;
}
