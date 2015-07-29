#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int st[30] = {0};

int cnt[26] = {0};

void upd(int n, int sign)
{
	int k = sqrt(n + .0);

	for (int i = 2; i <= k; i++)
		{
			while (n % i == 0)
				{
					st[i] += sign;
					n /= i;
				}
		}

	if (n > 1)
		st[n] += sign;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	cin >> s;

	int n = s.size();

	for (int i = 2; i <= n; i++)
		upd(i, 1);

	for (int i = 0; i < n; i++)
		cnt[s[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		{
			for (int j = 2; j <= cnt[i]; j++)
				upd(j, -1);
		}

	long long ans = 1;

	for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < st[i]; j++)
				ans *= i;
		}

	cout << ans;	

	return 0;
}
