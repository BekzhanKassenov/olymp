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
	int f[1];
	int k,i=0;
	while (i<n)
		{
			cin>>k;
			a.push_back(k);
			i++;
		}
	k=0;
	n--;
	i=0;
	f[0]=0;
	f[1]=0;
	while (k<=n)
		{
			f[i]+=max(a[k],a[n]);
			if (a[k]>=a[n])
				k++;
			else n--;
			i=1-i;
		}
	cout<<f[0]<<":"<<f[1];
	return 0;
}
