#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int z;
	vector <long long> a;
	while (cin>>z)
		a.push_back(z);
	sort(a.begin(),a.end());
	long long d=a[1]-a[0];
	for (int i=1;i<a.size();i++)
		if (a[i]-a[i-1]!=d)
			{
				cout<<"No";
				return 0;
			}
	 cout<<"Yes";
	 return 0;
}
