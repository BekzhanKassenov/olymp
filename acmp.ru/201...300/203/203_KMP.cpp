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

	int n = s.size();

	s = s + ('#' + t) + t;

	vector <int> pi(3 * n + 1);

	for (int i = 1; i < 3 * n + 1; i++)
		{
			int j = pi[i - 1];

			while (j > 0 && s[j] != s[i])
				j = pi[j - 1];

			if (s[i] == s[j])
				j++;

			pi[i] = j;
		}

  	for (int i = n + 1; i < 3 * n + 1; i++)
  		if (pi[i] == n)
  			{
  				cout << i - n - n;
  				return 0;
  			}

	cout << -1;

	return 0;
}
