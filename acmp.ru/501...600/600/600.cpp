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
	string s;
	for (int i=0;i<n;i++)
		{
			cin>>s;
			int len=s.length();
			if (len%3!=0) 
				{
					cout<<"NO"<<endl;
					continue;
				}
			int j=0;
			int s0=0,s1=0,s2=0;
			while (j<len && s[j]=='0')
				{
					s0++;
					j++;
				}
			while ((s[j]=='1') && (j<len))
				{
					s1++;
					j++;
				}
			while ((s[j]=='2') && (j<len))
				{
					s2++;
					j++;
				}
			if (s1==s2 && s1==s0 && s0+s1+s2==len) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	return 0;
}
