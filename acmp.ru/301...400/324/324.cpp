#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string  s;
	cin>>s;
	if (s[3]==s[0]  && s[1]==s[2])
		cout<<"YES";
	else cout<<"NO";
	return 0;
}
