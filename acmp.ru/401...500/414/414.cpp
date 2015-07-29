#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	int x,y;
	cin >> x >> y;
	vector <int> a(n+2,0);
	for (int i=2;i<=n;i++)
		cin>>a[i];
	a[1]=1;
	set <int> v;
	v.insert(x);
	v.insert(y);
	while (x!=y)
		{
			x=a[x];
			if (v.find(x)==v.end())
			v.insert(x);
			else
				if (x!=1)
					{
						cout<<x;
						return 0;
					}
			y=a[y];
			if (v.find(y)==v.end())
			v.insert(y);
			else
				if (y!=1)
					{
						cout<<y;
						return 0;
					}
		}
	cout<<1;
	return 0;
}
