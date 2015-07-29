#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[i]=x*3600+y*60+z;
		}
	sort(a.begin(),a.end());
	for (int i=0;i<n;i++)
		{
			cout<<a[i]/3600<<" ";
			a[i]%=3600;
			cout<<a[i]/60<< " ";
			a[i]%=60;
			cout<<a[i]<<endl;
		}
	return 0;
}
