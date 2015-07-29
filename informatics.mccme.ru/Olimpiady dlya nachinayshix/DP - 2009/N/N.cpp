#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

pair <string, int> cnt(string s)
{
	pair <string, int> ans;
	while (s[0] == ' ')
		{
			ans.second++;
			s.erase(s.begin());
		}
	ans.first = s;
	return ans;
}

bool is_file(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '.')
			return true;
	return false;
}

int main()
{
	freopen("in","r",stdin);
	stack <pair <string, int> > a;
	string f;
	cin >> f;
	string s;
	int n;
	cin >> n;
	vector <string> ans;
	for (int i = 0; i < n; i++)
		{
			cin >> s;
			pair <string, int> q = cnt(s);
			if (a.empty())
				a.push(q);
			else
				{
					if (is_file(q.first))
						if (q.first == f)
						{
							ans.push_back(f);
							while (!a.empty())
								{
									ans.push_back(a.top().first);
									a.pop();
								}
						   break;
						}
					else
						while (!a.empty() && q.second <= a.top().second)
							a.pop();
						a.push(q);

				}
		}
	for (int i = ans.size() - 1; i >= 0; i --)
		cout << '/' << ans[i];
	return 0;
}
