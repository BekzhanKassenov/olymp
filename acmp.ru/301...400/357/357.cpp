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
	int ans=0;
	int len=s.length();
	for (int i=0;i<len;i++)
		{
			ans+=int(s[i]-'0');
			i++;
			if (i<len)
			ans-=int(s[i]-'0');
		}
	if (ans%11==0)
		cout<<"YES";
	else cout<<"NO";
	return 0;
}
