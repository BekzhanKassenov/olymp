#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int cifra(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';

	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 10;
}

int f(string s, int b)
{
	int ans = 0;

	for (int i = 0; i < (int)s.length(); i++)
		{
			ans *= b;
			ans += cifra(s[i]);
		}

	return ans;	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	cin >> s;

	int n;

	cin >> n;

	int b = 0;

	for (int i = 0; i < (int)s.length(); i++)
		b = max(b, cifra(s[i]));

	for (int i = b; i <= 36; i++)
		{
			if (f(s, i) == n)
				{
					cout << i;
					return 0;
				}
		}

	cout << 0;

	return 0;
}
