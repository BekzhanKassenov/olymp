#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int k;
	for (int i=0;i<n;i++)
		{
			cin>>k;
			if (k<=437)
				{
					cout<<"Crash "<<i+1;
					return 0;
				}
		}
	cout<<"No crash";
	return 0;
}
