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
	vector <int> a;
	a.resize(n);
	int mn=0,mx=0;
	int s=0;
	for (int i=0;i<n;i++)
		{
			cin>>a[i];
			if (a[i]>a[mx]) mx=i;
			if (a[i]<a[mn]) mn=i;
			if (a[i]>0) s+=a[i];
		}
	cout<<s<<" ";
	s=1;
	for (int i=min(mx,mn)+1;i<max(mx,mn);i++)
		s*=a[i];
	cout<<s;
	return 0;
  	
}
