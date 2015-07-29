#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string get_next(string& s, int& pos)
{
	string ans;

	if (s[pos] != '<')
		return ans;

	pos++;

	for (; s[pos] != '>' && pos < (int)s.length(); pos++)
		{
			if (s[pos] == '<')
				{
					ans.clear();
					return ans;
				}
			ans += s[pos];
		}

	pos++;

	return ans;
}

bool check(string& s)
{
	stack <string> st;

	int i = 0;

	while (i < (int)s.length())
		{
			int k = i;
			
			string tmp = get_next(s, i);

			if (tmp.empty())
				return false;

			for (int j = 1; j < (int)tmp.length(); j++)
				if (tmp[j] == '/')
					return false;

			if (tmp[0] == '/')
				{
					if (st.empty())
						return false;
					string z = st.top();
					st.pop();
					if ('/' + z != tmp)
						return false;
				}
			else
				{
					st.push(tmp);
				}
		}
	if (!st.empty())
		return false;

	return true;

}

int main()
{
	freopen("xml.in", "r", stdin);
	freopen("xml.out", "w", stdout);
	string s;

	cin >> s;

	string alphabet = "qwertyuiopasdfghjklzxcvbnm<>/";

	for (int i = 0; i < (int)s.length(); i++)
		{
			char k = s[i];
			for (int j = 0; j < 29; j++)
				{
					s[i] = alphabet[j];
					if (check(s))
						{
							cout << s;
							return 0;
						}
				}
			s[i] = k;
		}
}
