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
	vector <int> a(n);
	vector <int> d(n,0);
	vector <int> ans(n);
	vector <int> k;

	for (int i=0;i<n;i++)
		cin>>a[i];
	d[0]=a[0];
	ans[0]=-1;
	d[1]=max(a[1]+a[0],a[1]);

	if (a[0]<0) ans[1]=-1;
	else ans[1]=0;
	
	for (int i=2;i<n;i++)
		{
			if (d[i-1]>d[i-2]) ans[i]=i-1;
			else ans[i]=i-2;
			d[i]=max(d[i-1],d[i-2])+a[i];
		}
	int i=n-1;
	do
		{
			k.push_back(i+1);
			i=ans[i];
		}
   while (i!=-1);
	cout<<d[n-1]<<endl;
	for (int i=k.size()-1;i>=0;i--)
		cout<<k[i]<<' ';
	return 0;
}
