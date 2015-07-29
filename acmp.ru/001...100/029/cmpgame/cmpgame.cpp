#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int z;
	vector <int> a;
	for (int i=0;i<n;i++)
		{
			cin>>z;
			a.push_back(z);
		}
	vector <int> ms;
	ms.push_back(0);
	ms.push_back(abs(a[1]-a[0]));
	for (int i=2;i<n;i++)
		{
			ms.push_back((min(abs(a[i]-a[i-1])+ms[i-1],3*abs(a[i]-a[i-2])+ms[i-2])));
		}
	cout<<ms[n-1];
	return 0;
}
