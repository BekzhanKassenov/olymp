#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	set <string> s1, s2;

	int n;

	cin >> n;

	set <string> ans1, ans2, ans3;

	for (int i = 0; i < n; i++)
     	{
     		string s;
     		cin >> s;
     		s1.insert(s);
		}

	int m;

	cin >> m;

	for (int i = 0; i < m; i++)
		{
			string s;
			cin >> s;
			s2.insert(s);
		}

	for (set <string> :: iterator it = s1.begin(); it != s1.end(); it++)
		{
			if (s2.find(*it) != s2.end())
				ans3.insert(*it);
			ans1.insert(*it);
		}

	for (set <string> :: iterator it = s2.begin(); it != s2.end(); it++)
		{
			if (s1.find(*it) != s1.end())
				ans3.insert(*it);
			else
				ans2.insert(*it);
		}

	cout << "Friends: ";

	vector <string> c;

	c.assign(ans1.begin(), ans1.end());

	for (int i = 0; i < (int)c.size(); i++)
		{
			cout << c[i];
			if (i != (int)c.size() - 1)
				cout << ", ";
		}

	cout << endl;	

	cout << "Mutual Friends: ";

	c.assign(ans3.begin(), ans3.end());

	for (int i = 0; i < (int)c.size(); i++)
		{
			cout << c[i];
			if (i != (int)c.size() - 1)
				cout << ", ";
		}

	cout << endl;	

	cout << "Also Friend of: ";

	c.assign(ans2.begin(), ans2.end());

	for (int i = 0; i < (int)c.size(); i++)
		{
			cout << c[i];
			if (i != (int)c.size() - 1)
				cout << ", ";
		}

	cout << endl;	

	return 0;
}

