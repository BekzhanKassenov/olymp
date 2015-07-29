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
	if (s.length()!=6) 
	{
		cout<<"NO";
		return 0;
	}
	if (s[0]+s[1]+s[2]==s[3]+s[4]+s[5])
		cout<<"YES";
	else cout<<"NO";
	return 0;
}
