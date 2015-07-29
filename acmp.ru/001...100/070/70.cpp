#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	int n;
	cin>>s;
	cin>>n;
	if (n>0)
		{
			int z=0;
			if (s.length()*n>1023)
			while (z<=1023)
				{	
					for (int i=0;i<s.length();i++,z++)
						cout<<s[i];
					return 0;
				}
			else
				for (int i=0;i<n;i++)
					cout<<s;
			return 0;
		}
	if (n<0)
		{	
			int len=s.length();
			n*=(-1);
			if (len%n!=0)
				{
					cout<<"NO SOLUTION";
					return 0;
			  	}
			int i=0;
			while (i<len-len/n)
				{	
					if (s.substr(i,len/n)!=s.substr(i+len/n,len/n))
						{
							cout<<"NO SOLUTION";
							return 0;
					   }
					i+=len/n;
				}
			cout<<s.substr(0,len/n);
			return 0;
		}
	cout<<"NO SOLUTION";
	return 0;
}
