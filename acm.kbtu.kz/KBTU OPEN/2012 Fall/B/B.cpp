#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

#define MOD 235147349
#define int long long

int str_to_int(string s)
{
	stringstream ss;

	ss << s;

	int ans;

	ss >> ans;

	return ans;
}

int a[1000];

string s;

int len;

int aq = 0;

vector <int> dp;

int rec(int pos)
{
	if (dp[pos] != -1)
		return dp[pos];

	if (pos == len)
		return 1;

	int ans = 0;

	bool flag = false;

	for (int i = 1; i <= 3; i++)
		{
			if (pos + i > len)
				break;

			string tmp = s.substr(pos, i);

			int t = str_to_int(tmp);

			if (a[t] != 0)
				{
					flag |= rec(pos + i);
					ans = (ans + (a[t] * rec(pos + i)) % MOD) % MOD;
				}
		}
	if (!flag)
		return (dp[pos] = 0);
	return (dp[pos] = ans);
}

main()
{
	freopen("chatting.in", "r", stdin);
	freopen("chatting.out", "w", stdout);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		{
			cin >> s;
			a[s.length()]++;
		}
	
	cin >> s;

	len = s.length();

	dp.resize(len + 1, -1);

	aq = rec(0);

	cout << aq % MOD;
}
