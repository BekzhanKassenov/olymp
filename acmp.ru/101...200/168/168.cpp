#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string int_to_string(int i)
{
	string ans;
	int a=i;
	while (a>0)
		{
			ans+=char((a%10)+'0');
			a/=10;
		}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string n;
	cin>>n;
	string ans;
	int i=0, s=1;
	bool solved=false;
	int len=n.length();
	while (!solved)
		{
			ans+=int_to_string(s);
			s++;
			while (i+len<ans.length())
				{
					if (ans.substr(i,len)==n)
						{
							solved=true;
							break;
						}
					i++;
				}
		}
   cout<<i+1;
	return 0;
}
