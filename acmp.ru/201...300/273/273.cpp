#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string int_to_str(int n)
{
	int c=n;
	string ans;
	while (c>0)
		{
			ans+=c%10+'0';
			c/=10;		
		}
	reverse(ans.begin(),ans.end());
	return ans;
}

int tap(string s, char c, int pos)
{
	for (int i=pos;i<s.length();i++)
		if (s[i]==c) return i;
	return -1;
}

bool test(string a, string s)
{
	int i=tap(s,a[0],0);
	if (i==-1)
		return false;
	i=tap(s,a[1],i+1);
	if (i==-1)
		return false;
	i=tap(s,a[2],i+1);
	if (i==-1) 	
		return false;
	return true;	
}

int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin>>s;
	int ans=0;
	for (int i=100;i<=999;i++)
		if (test(int_to_str(i),s)) ans++;
   cout<<ans;
   return 0;
}
