#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin>>s;
	int i=s.length()-1;
	int sum=0;
	while (s[i]=='0')
		{	
			sum++;
			i--;
		}
	cout<<1;
	for (i=1;i<=sum;i++)
		cout<<0;
	return 0;
}
