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
	int len=s.length();
	int ans=0;
	for (int i=0;i<len-4;i++)
		if (s.substr(i,5)==">>-->" || s.substr(i,5)=="<--<<") ans++;
	cout<<ans;
}

