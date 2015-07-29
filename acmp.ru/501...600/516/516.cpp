#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int str_to_int(string a)
{	
	int ans=0;
	for (int i=0;i<a.length();i++)
		{	
			ans*=10;
			ans+=a[i]-'0';
		}
	return ans;
}

bool prost(int n)
{
	int k=int(sqrt(double(n)));
	for (int i=2;i<=k;i++)
		if (n%i==0)
			return false;
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	bool lg=prost(str_to_int(s));
	reverse(s.begin(),s.end());
	lg= lg && prost(str_to_int(s));
	if (lg)
		cout<<"Yes";
	else 
		cout<<"No";
	return 0;
}
