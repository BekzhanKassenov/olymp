#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for (int i=0;i<n;i++)
		{	
			string s;
			cin>>s;
			if (s[0]==s[3])
			ans++;
		}
	cout<<ans;
	return 0;
}
