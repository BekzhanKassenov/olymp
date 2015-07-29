#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string s;

	int x = 0;

	cin >> s;

	int mx = 1;

	for (int i = 0; i < (int)s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				{
					x += s[i] - '0';
					mx = max(mx, s[i] - '0');
				}

			else
				{
					x += s[i] - 'A' + 10;
					mx = max(mx, s[i] - 'A' + 10);
				}
		}

	for (int i = mx + 1; i <= 36; i++)
		if (x % (i - 1) == 0)
			{
				cout << i;
				return 0;
			}

	cout << "No solution.";
	return 0;
}
