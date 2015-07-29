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
	vector <int> a(n),b(n,1);
	for (int i=0;i<n;i++)
		cin>>a[i];
	int mx=1;
	for (int i=1;i<n;i++)
		{
			for (int j=0;j<i;j++)
				if (a[j]<a[i] && (b[j]>=b[i] || b[i]==1))
					b[i]=b[j]+1;
			if (b[i]>mx) mx=b[i];
		}
	cout<<mx;
	return 0;
}
