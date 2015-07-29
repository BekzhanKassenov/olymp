#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++)
		cin>>a[i];
	vector <bool> used(n,false);
	bool lg=false;
	while (!lg)
		{
			int mn=999999;
			
			for (int i=0;i<n;i++)
				if (!used[i])
					mn=min(mn,a[i]);
			
			for (int i=0;i<n;i++)
				if (a[i]==mn)
					used[i]=true;
			
			for (int i=0;i<n-1;i++)
				if (used[i] && used[i+1])
					{
						cout<<mn;
						lg=true;
						return 0;
					}
			
			if (used[0] || used[n-1])
				{
					cout<<mn;
					lg=true;
					return 0;
				}
		}
	return 0;
}
