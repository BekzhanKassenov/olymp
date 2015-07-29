#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>m>>n;
	vector <int> a(64200,0);
	int z;
	for (int i=0;i<m;i++)
		{
			cin>>z;
			if (a[z+32000]==0) a[z+32000]++;
		}
	for (int i=0;i<n;i++)
		{
			cin>>z;
			if (a[z+32000]==0) 
				{
					cout<<0;
					return 0;
				}
			if (a[z+32000]==1) a[z+32000]++;
		}
   for (int i=0;i<64200;i++)
   	if (a[i]==1) 
   		{
   			cout<<"0";
   			return 0;
   		}
	cout<<'1';
	return 0;
}
 
