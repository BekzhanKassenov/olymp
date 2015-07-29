#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	int len=b.length();
	if (a.length()!=len) 
		{
			cout<<"NO";
			return 0;
		}
	int c=0;
	int s[2];
	s[0]=0;
	s[1]=0;
	int m=0;
	for (int i=0;i<len;i++)
		if (a[i]!=b[i])
			{
				if (m<2)
					{
						s[m]=i;
						m++;
					}
				else 
					{
						cout<<"NO";
						return 0;
					}
			}
	if ((a[s[0]]==b[s[1]]) && (b[s[0]]==a[s[1]]))
		cout<<"YES";
	else cout<<"NO";
	return 0;
}
