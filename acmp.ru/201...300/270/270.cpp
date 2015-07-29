#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string cpp_to_java(const string& s)
{
	bool b = false;

	string ans;

	int len = s.size();

	for (int i = 0; i < len; i++)
		{
			if (s[i] ==  '_')
				b = true;
			else
				if (b)
					{
						ans += toupper(s[i]);
						b = false;
					}
				else
					ans += s[i];	
		}

	return ans;	
}

string java_to_cpp(const string& s)
{
	string ans;

	int len = s.size();

	for (int i = 0; i < len; i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				{
					ans += '_';
					ans += tolower(s[i]);
				}
			else
				ans += s[i];	
		}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	cin >> s;

	int len = s.size();

	bool bad = false, cpp = false, java = false;

	for (int i = 0; i < len; i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				if (i == 0)
					bad = true;
				else
					java = true;

			if (s[i] == '_')
				{
					if (i == 0 || i == len - 1)
						bad = true;
					else
						cpp = true;

					if (i > 0 && s[i - 1] == '_')
						bad = true;

					if (i < len - 1 && s[i + 1] == '_')
						bad = true;
				}
		}

 	if (cpp && java)
 		bad = true;

   	if (bad)
   		puts("Error!");
   	else
   		{
   			if (cpp)
   				cout << cpp_to_java(s) << endl;
   			else
   				cout << java_to_cpp(s) << endl;

   		}

   	return 0;
}
