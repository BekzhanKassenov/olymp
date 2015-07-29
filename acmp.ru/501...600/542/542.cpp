#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	string s;
	while (n>0)
		{
			s += n % 2;
			n /= 2;
		}
	reverse(s.begin(),s.end());
	for (int i=0;i<s.length();i++)
		{
			if (s[i]==1)
				{
					n+= (1 << i);
				}
		}
	cout << n;
}
