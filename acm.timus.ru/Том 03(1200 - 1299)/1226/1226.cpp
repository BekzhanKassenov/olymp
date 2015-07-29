#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;

int len;

bool letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

string get_word(int &pos)
{
	string ans;

	while (letter(s[pos]) && pos < len)
		ans += s[pos++];
	
	return ans;
}

int main()
{
   #ifndef ONLINE_JUDGE
   	freopen("in", "r", stdin);
   #endif

	while (getline(cin, s))
		{
			int pos = 0;
   
   		len = s.length();
   		
			while (pos < len)
				{
					if (letter(s[pos]))
						{
							string tmp = get_word(pos);
							reverse(tmp.begin(), tmp.end());
							cout << tmp;
						}
					else
						cout << s[pos++];
				}
			cout << endl;
		}

	return 0;
}
