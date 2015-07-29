#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check(char c1, char c2)
{
	if ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || c1 == '{')
		return true;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	stack <char> st;
	int ans = 0;
	int len = s.length();
	if (len % 2 == 1)
		{
			cout << -1;
			return 0;
		}
	for (int i = 0;  i < len; i++)
		{
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			else
				{
					if (!st.empty())
						{
							char k = st.top();
							st.pop();
							if (!check(k, s[i]))
								ans++;
						}
					else
						{
							cout << -1;
							return 0;
						}
				}
		}
	cout << ans;
	return 0;
}
