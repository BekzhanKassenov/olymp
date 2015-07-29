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
		cin>>a[i];
	reverse(a.begin(),a.end());
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
