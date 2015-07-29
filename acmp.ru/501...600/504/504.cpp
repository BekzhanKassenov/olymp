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
	string s="GCV";
	for (int i=1;i<=n;i++)
		{
			char k=s[2];
			s[2]=s[1];
			s[1]=s[0];
			s[0]=k;
		}
	cout<<s;
	return 0;
}
