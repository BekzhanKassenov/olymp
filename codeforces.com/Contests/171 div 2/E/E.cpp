/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

string operator - (string& s, string& t)
{
	string ans;

	for (int i = 0; i < (int)t.size(); i++)
		{
			if (s[i] < '0')
				{
					while (s[i] < '0')
						{
							s[i + 1]--;
							s[i] += 2;
						}
				}

			if (s[i] == t[i])
				ans += '0';

			if (s[i] == '1' && t[i] == '0')
				ans += '1';

			if (s[i] == '0')
				{
					if (t[i] == '1')
						{
							s[i + 1]--;
							s[i] += 2;
							ans += s[i] - t[i] + '0';
							s[i]--;
						}
				}
		}

   	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	cin >> s;

	reverse(s.begin(), s.end());

	string t = s;

	int ans = 0;

	for (int i = 0; i < (int)t.size(); i++)
		{
			t[i] = '0';
			ans += s[i] - '0';
		}

	t += '1';

	string tmp = t - s;

	int q = 0;

	for (int i = 0; i < (int)tmp.size(); i++)
		q += tmp[i] - '0';

	q++;	

	reverse(tmp.begin(), tmp.end());

	while (tmp[0] == '0')
		tmp.erase(tmp.begin());

	cerr << tmp << endl;

	cout << min(q, ans);	

	return 0;
}
