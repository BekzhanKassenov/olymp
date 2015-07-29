#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

bool can(string a, string b)
{
	if (a.size() != b.size())
		return false;

	bool flag = false;

	for (int i = 0; i < (int)a.size(); i++)
		{
			if (a[i] != b[i])
				if (flag)
					return false;
				else
					flag = true;
		}

	return flag;	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	
	cin >> n;

	vector <string> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <int> cnt(n, 0);

	int m;

	cin >> m;

	string s;

	for (int i = 0; i < m; i++)
		{
			cin >> s;

			for (int j = 0; j < n; j++)
				if (can(a[j], s))
					cnt[j]++;
		}

	for (int i = 0; i < n; i++)
		cout << cnt[i] << ' ';

	return 0;
}
