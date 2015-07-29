#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, t;

	cin >> s >> t;

	int lens = s.length();

	int lent = t.length();

	for (int q = 0; q < 27; q++)
		{
			for (int i = 0; i <= (lens - lent); i++)
				{
					if (s.substr(i, lent) == t)
						{
							cout << s << endl;
							return 0;
						}
				} 

			for (int i = 0; i < lens; i++)
				{
					s[i] = (s[i] - 'A' - 1 + 26) % 26 + 'A';
				}
		}

	cout << "IMPOSSIBLE";
	return 0;
}
