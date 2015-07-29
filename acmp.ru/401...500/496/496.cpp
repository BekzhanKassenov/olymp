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
	for (int i=0;i<n;i++)
		cin>>a[i];
	int mx=a[0]+a[1]+a[n-1];
	mx=max(mx,a[n-1]+a[n-2]+a[0]);
	for (int i=1;i<=n-2;i++)
		mx=max(mx,a[i]+a[i-1]+a[i+1]);
	cout<<mx;
	return 0;
}
