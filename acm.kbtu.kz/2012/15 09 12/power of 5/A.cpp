#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define INF 2000000000
#define F first
#define S second

string int_to_bin_str(ll n)
{
	string ans;
	while (n)
		{
			ans += (n % 2) + '0';
			n /= 2;
		}
	reverse(ans.begin(), ans.end());
	return ans;
}

ll bin_str_to_int(string s)
{
	ll ans = 0;
	for (ll i = 0; i < (ll)s.length(); i++)
		{
			ans *= 2;
			ans += s[i] - '0';
		}
	return ans;
}

int main()
{
	string s;
	cin >> s;

	if (s[0] == '0')
		{
			cout << -1;
			return 0;
		}
	
	vector <pair <string, int> > pws(25);

	int n = 0;
	
	int len = (int)s.length();
	
	for (ll i = 1; i <= (bin_str_to_int(s)); i *= 5)
		{
			pws[n].F = int_to_bin_str(i);
			pws[n].S = (int)pws[n].F.length();
			n++;
		}

   vector <int> dp(len, INF);
	
	for (int i = 0; i < n; i++)
		{
			if (pws[i].S <= len && s.substr(0, pws[i].S) == pws[i].F)
				{
					dp[pws[i].S - 1] = 1;
				}
		}
	
	for (int i = 1; i < len; i++)
		{
			if (s[i] == '1' && dp[i - 1] < INF)
				{
					for (int j = 0; j < n; j++)
						{
							if (i + pws[j].S > len)  	
								break;
							if (s.substr(i, pws[j].S) == pws[j].F)
								{
									dp[i + pws[j].S - 1] = min(dp[i + pws[j].S - 1], dp[i - 1] + 1);
								}
						}	
				}
		}
	
	if (dp[len - 1] < INF)
		cout << dp[len - 1];
	else
		cout << -1;
	
	return 0;
}

