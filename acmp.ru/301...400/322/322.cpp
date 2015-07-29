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
	int f2=1,f1=1,f=0;
	while (f1<=len)
		{
			cout<<s[f1-1];
			f=f1+f2;
			f2=f1;
			f1=f;
		}
	return 0;
}
