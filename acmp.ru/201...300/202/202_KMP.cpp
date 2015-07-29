#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, t;

	cin >> s >> t;

	int len = t.length();

	t += ('#' + s);

	int n = (int)(s.length() + len + 1);

	vector <int> pr(n);

	for (int i = 1; i < n; i++)
		{
			int j = pr[i - 1];

			while (j > 0 && t[j] != t[i])
				j = pr[j - 1];

			if (t[i] == t[j]) j++;

			pr[i] = j;
		}


	for (int i = 0; i < n; i++)
		if (pr[i] == len)
			printf("%d ", i - len - len);

	return 0;
}

