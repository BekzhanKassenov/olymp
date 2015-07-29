#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string dec_to_bin(int n)
{
	string ans;
	int c=n;
	while (c>0)
		{
			ans+=c%2+'0';
			c/=2;
		}
	reverse(ans.begin(),ans.end());
	return ans;
}

int bin_to_dec(string s)
{
	int ans=0;
	string c=s;
	reverse(c.begin(),c.end());
	for (int i=0;i<c.length();i++)
		if (c[i]=='1')  ans+=1<<i;
	return ans;
}

void move(string& s)
{
	char k=s[0];
	for (int i=0;i<s.length()-1;i++)
		s[i]=s[i+1];
	s[s.length()-1]=k;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	if (n==0)
		{
			cout<<0;
			return 0;
		}
	int ans=n;
	string s=dec_to_bin(n);
	for (int i=0;i<=s.length();i++)
		{
			move(s);
			int k=bin_to_dec(s);
			ans=max(ans,k);
		}
   cout << ans;
   return 0;
}
