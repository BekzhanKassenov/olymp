#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector <int> a(10,0);
	for (int j=0;j<3;j++)
		{
			string s;
			cin>>s;
			for (int i=0;i<s.length();i++)
				{
					if (a[s[i]-'0']==j)
						a[s[i]-'0']++;
				}
		}
	int ans=0;
	for (int i=0;i<10;i++)
		if (a[i]==3)
			ans++;
 	cout<<ans<<endl;
 	for (int i=0;i<10;i++)
 		if (a[i]==3)
 			cout<<i<<' ';
 	return 0;
}
