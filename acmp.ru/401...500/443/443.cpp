#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int base;

int MOD;

int get_hash(const string &s)
{
	int len = s.length();
	int ans = s[len - 1] - '0';

	for (int i = len - 2; i >= 0; i--)
		{
			ans *= base;
			ans += s[i] - '0';
			ans %= MOD;
		}

	return ans;	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n >> MOD >> base;

	vector <int> cnt(MOD);

	for (int i = 0; i < n; i++)
		{
			string s;

			cin >> s;

			cnt[get_hash(s)] ++;
		}

	long long ans = 0;

	for (int i = 0; i < MOD; i++)
		{
			if (cnt[i] > 1)
				ans += (cnt[i] * (cnt[i] - 1)) / 2;
		}

	cout << ans;

	return 0;	
}

