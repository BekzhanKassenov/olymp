#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int n,k;
string s;

int stp1(int k)
{
	int ans=1;
	for (int i=0;i<k;i++)
		ans*=10;
	return ans;
}

int val(string s)
{
	int st=s.length();
	int ans=0;
	while (st>0)
		{
			ans+=(s[s.length()-st]-'0')*stp1(st-1);
			st--;
		}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>k;
	cin>>s;
	vector <int> a;
	a.resize(stp1(k));
	int len=s.length();
	for (int i=0;i<len-k;i++)
		a[val(s.substr(i,k))]++;
   for (int i=0;i<stp1(k);i++)
   	if (a[i]>=2)
   		{
   			cout<<"YES";
   			return 0;
   		}
   cout<<"NO";
	return 0;
}
