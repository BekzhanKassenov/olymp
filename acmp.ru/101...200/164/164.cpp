#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;

int len;

int ck(int a)
{
	if (a < 10)
		return a;
	int ans = 0;
	while (a > 0)
		{	
			ans += a % 10;
			a /= 10;
		}
	return ck(ans);
}

int ck (string s)
{	
	int a = 0;
	for (int i = 0; i < s.length(); i++)
		a += s[i] - '0';
	return ck(a);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> s;
	len = s.length();
	for (int i = 1; i <= len - 1; i++)
		{
			if (ck(s.substr(0,i)) == ck(s.substr(i, len - i)))
				{
					cout << "YES";
					return 0;
				}
		}
	cout << "NO";
	return 0;
}
