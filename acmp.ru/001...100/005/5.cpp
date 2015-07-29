#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int s=0;
	int a[120];
	
	for (int i=0;i<n;i++)
		{
			cin>>a[i];
			if (a[i]%2==1) 
				{ 
					cout<<a[i]<<" ";
					s++;
				}
		}
	cout<<endl;
	for (int i=0;i<n;i++)
		if (a[i]%2==0)
			{
				cout<<a[i]<<" ";
				s--;
			}
	cout<<endl;
	if (s<=0) cout<<"YES";
	else cout<<"NO";
	return 0;
}
