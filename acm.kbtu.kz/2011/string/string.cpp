#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>s;
	char mx='a', mn='z';
	int len=s.length();
	for (int i=0;i<len;i++)
		{
			if (s[i]>mx) mx=s[i];
			if (s[i]<mn) mn=s[i];
		}
	if (mn==mx)
		{
			cout<<mn;
			return 0;
		}
	string c,k;
	for (int i=0;i<len;i++)
		{
			if ((s[i]==mx) || (s[i]==mn))
				{
					c+=s[i];
					k+=i;
				}	
		}
  	int lenc=c.length();
  	int l=0,r=999999;
  	for (int i=0;i<lenc;i++)
  		{
  			if ((c[i]!=c[i+1]) && (abs(int(k[i])-int(k[i+1]))<abs(l-r)))
  				{
  					l=int(k[i+1]);
  					r=int(k[i]);
  				}
  		}
  	for (int i=r;i<=l;i++)
  		cout<<s[i];
  	return 0;
}
