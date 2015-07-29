#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

bool test (string s)
{	
	int len=s.length();
	for (int i=0;i<len/2;i++)
		if (s[i]!=s[len-i-1]) return false;
	return true;
}

bool pal(int n,int k)
{
	int c=n;
	string s="";
	while (c>0)
		{	
			s+=c%k;
			c/=k;	
		}
   return test(s);
}  

int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <int> ans;
	for (int i=2;i<=36;i++)
		{
			if (pal(n,i)) ans.push_back(i);
		}
	int len=ans.size();
	if (len==0)
		{
			cout<<"none";
		}
	if (len==1)
		{
			cout<<"unique"<<endl;
			cout<<ans[0];
		}
	if (len>1)
		{
			cout<<"multiple"<<endl;
			for (int i=0;i<len;i++)
				cout<<ans[i]<<' ';
		}	
	return 0;
}
