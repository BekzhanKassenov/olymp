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
	int k;
	cin>>k;
	int z;
	for (int i=0;i<k;i++)
		{	
			cin>>z;
			a[z-1]--;
		}
	for (int i=0;i<n;i++)
		if (a[i]<0) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
	return 0;
}
