#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

bool sravn(string a,string b)
{
    int len=a.length();
    if (len==b.length())
        {
            if (a>b) return false;
            else return true;
        }
    if (len<b.length()) return true;
    return false;
}

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

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[10];
	for (int i=0;i<10;i++)
		a[i]=0;
  	for (int i=9;i>=2;i--)
  		{
  			while (k%i==0)
  				{
  					a[i]++;
  					k/=i;
  				}
  		}
  	if (k!=1)
  		{	
  			cout<<"NO";
  			return 0;
  		}
  	string s;
  	for (int i=2;i<10;i++)
  		{
  			for (int j=1;j<=a[i];j++)
  				s+=i+'0';
  		}
  	if (sravn(s,int_to_str(n)))
  		cout<<"YES";
  	else cout<<"NO";
	return 0;
}
