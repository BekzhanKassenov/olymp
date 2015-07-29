#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <long long> a(n);
	for (int i=0;i<n;i++)
		cin>>a[i];
	int m;
	cin>>m;
	for (int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			for (int j=x-1;j<y;j++)
				cout<<a[j]<<" ";
			cout<<endl;
		}
	return 0;
}
