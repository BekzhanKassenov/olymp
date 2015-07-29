#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int sum(int n)
{
	int ans = 0;

	while (n)
		{
			ans += n % 10;
			n /= 10;
		}

	return ans;	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	cin >> s;

	int s1 = s[0] + s[1] + s[2] - 3 * '0';

	int c = (s[3] - '0') * 100 + (s[4] - '0') * 10 + s[5] - '0';

	c++;

	if (c != 1000 && sum(c) == s1)
		{
			cout << "Yes";
			return 0;
		}

	c -= 2;

	if (c >= 0 && sum(c) == s1)
		{
			cout << "Yes";
			return 0;
		}
	cout << "No";
	return 0;
}
