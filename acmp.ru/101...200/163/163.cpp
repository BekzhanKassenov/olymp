#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin>>s;
	if (s[0]=='x')
		{
			if (s[1]=='-')
				cout<<int((s[4]-'0'+s[2]-'0'));
			else
				cout<<int(s[4]-s[2]);
		}
	if (s[2]=='x')	
		{
			if (s[1]=='-')
				cout<<int(s[0]-s[4]);
			else
				cout<<(int(s[4]-s[0]));
		}
	if (s[4]=='x')
		{
			if (s[1]=='+')
				cout<<int(s[0]-'0'+s[2]-'0');
			else
				cout<<int(s[0]-s[2]);
		}
	return 0;
}
