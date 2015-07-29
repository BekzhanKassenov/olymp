#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string prv(string s, int b)
{
	long long flag=0;
	string ans;
	for (int i=s.length()-1;i>=0;i--)
		{	
			flag+=(long long)(s[i]-'0')*(long long)(b);
			ans+=char(int(flag%10+int('0')));
			flag/=10;
		}
	while (flag>0)
		{
			ans+=char(flag%10)+'0';
			flag/=10;
		}
	reverse(ans.begin(),ans.end());	
  	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin>>s;
	int b;
	cin>>b;
	if (s[0]==0 || b==0)
		{
			cout<<0;
			return 0;
		}
	cout<<prv(s,b);
	return 0;
}
