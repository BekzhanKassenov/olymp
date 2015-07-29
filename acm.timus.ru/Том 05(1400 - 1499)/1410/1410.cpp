#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_letter(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int next_word(const string& s, int& pos, int len)
{
    int ans = 0;

    while (pos < len && !is_letter(s[pos]))
    	pos++;

	while (pos < len && is_letter(s[pos]))
		{
			ans++;
			pos++;
		}

	pos++;	

   	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	vector <int> a;

	while (getline(cin, s))
		{
			int len = s.size();

			int pos = 0;

			while (pos < len)
				{
					int k = next_word(s, pos, len);
					a.push_back(k);
				}
		}        

	int n = a.size();

	/*cout << n << endl;

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';

	cout << endl;*/	

	vector <int> dp(n);

	int ans = 0;

	if (n > 0) {
		dp[0] = a[0];
		ans = dp[0];
	}	

	if (n > 1) {
		dp[1] = a[1];
		ans = max(ans, dp[1]);
	}

	for (int i = 2; i < n; i++)
		{
			dp[i] = dp[i - 1];

			for (int j = 0; j <= i - 2; j++)
				dp[i] = max(dp[i], dp[j] + a[i]);

			ans = max(ans, dp[i]);
		}

	/*if (n > 0)
		cout << dp[n - 1];
	else
		cout << 0;	*/

	cout << ans;

	return 0;
}
