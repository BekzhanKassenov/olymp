#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int len;

bool gl(char a)
{
	if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
		return true;

	return false;
}

bool check(string s)
{
	bool L = false;
	if ((len != 0 && s[0] == 'L') || (len > 1 && s[1] == 'L'))
		L = true;
	for (int i = 2; i < len; i++)
		{
			bool a1 = gl(s[i - 2]);
			bool a2 = gl(s[i - 1]);
			bool a3 = gl(s[i]);

			if (a1 && a2 && a3)
				return false;

			if (!a1 && !a2 && !a3)
				return false;

		  	if (s[i] == 'L')
		  		L = true;
		}
	if (L)
		return true;

	return false;
}

int main()
{
	string s;
	cin >> s;

	len = (int)s.length();

	int nmb = 0;

	bool L = false;

	for (int i = 0; i < len; i++)
		{
			if (s[i] == '_')
				nmb++;

			if (s[i] == 'L')
				L = true;
		}

		
 	
}
