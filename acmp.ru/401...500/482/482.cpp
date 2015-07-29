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

string psl (int n)
{
	string ans;
	for (int i=1;i<=n;i++)
		ans+=int_to_str(i);
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	string s;
	int i=1;
	while (s.length()<=n)
		{
			s+=psl(i);
			i++;
		}
	cout<<s[n-1];
	return 0;
}
