#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, t;

	cin >> s >> t;

	int len = t.size();

	s = t + '#' + s;

	vector <int> z(s.size());

	z[0] = 0;

	int n = z.size();

	for (int i = 1, l = 0, r = 0; i < n; i++)
		{
			if (i <= r)
				z[i] = min(z[i - l], r - i + 1);

			while (i + z[i] < n && s[i + z[i]] == s[z[i]])
				z[i]++;

			if (i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
		}

	for (int i = len + 1; i < n; i++)
		{
			if (z[i] == len)
				printf("%d ", i - len - 1);
		}

	return 0;	
}

