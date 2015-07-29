#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin >> s;
	bool palin = true;
	bool od = true;
	int len = s.length();
	if (len == 1)
		{
			cout << "NO SOLUTION";
			return 0;
		}
	for (int i = 0; i < len / 2; i++)
		{
			if (s[i] != s[len - i - 1])
				{
					palin = false;
					break;
				}
			if (s[i] != s[i + 1])
				od = false;
		}
	if (!palin)
		cout << s;
	else
		if (!od)
			cout << s.substr(0, len - 1);
		else
			cout << "NO SOLUTION";
	return 0;
}
