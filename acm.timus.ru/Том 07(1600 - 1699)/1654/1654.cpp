#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	cin >> s;

	stack <char> st;

	for (int i = 0; i < (int)s.length(); i++)
		{
			if (st.empty() || st.top() != s[i])
					st.push(s[i]);
			else
				st.pop();
		}

	s.clear();

	while (!st.empty())
		{
			s += st.top();
			st.pop();
		}	

	reverse(s.begin(), s.end());

	cout << s;

	return 0;
}
