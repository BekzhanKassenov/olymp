/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS

int cnt[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date
{
	int d, m, y;

	date() {d = m = y = 0;}

	bool check()
		{
			
			//cout << "CHECKING" << endl;

			//cout << d << ' ' << m << ' ' << y << endl;
			if (y < 2013 || y > 2015)
				return false;

			if (m < 1 || m > 13)
				return false;
			
			if (d < 1 || d > cnt[m])
				return false;
			return true;
		}
};

bool operator == (date a, date b)
{
	if (a.d == b.d && a.m == b.m && a.y == b.y)
		return true;

	return false;
}

bool operator < (date a, date b)
{
	if (a.y < b.y)
		return true;

	if (a.y > b.y)
		return false;

	if (a.m < b.m)
		return true;

	if (a.m > b.m)
		return false;

	if (a.d < b.d)
		return true;

	return false;
}

int str_to_int(string s)
{
	int ans = 0;

	for (int i = 0; i < (int)s.length(); i++)
		{
			ans *= 10;

			ans += s[i] - '0';
		}

	return ans;
}

date get_date(const string &s, int pos)
{
	date ans;

	date wa;

	wa.d = wa.m = wa.y = -1;

	string tmp;

	if (s[pos] == '-' || s[pos + 1] == '-')
		return wa;

	tmp += s[pos];

	tmp += s[pos + 1];

	if (s[pos + 2] != '-')
		return wa;

	ans.d = str_to_int(tmp);

	tmp.clear();

	if (s[pos + 3] == '-' || s[pos + 4] == '-')
		return wa;

	tmp += s[pos + 3];
	tmp += s[pos + 4];

	if (s[pos + 5] != '-')
		return wa;

	ans.m = str_to_int(tmp);

	tmp.clear();

	for (int i = 6; i <= 9; i++)
		{
			if (s[pos + i] == '-')
				return wa;

			tmp += s[pos + i];
		}


	ans.y = str_to_int(tmp);

	if (ans.check())
		return ans;
	else
		return wa;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	getline(cin, s);

	map <date, int> m;

	date ans = date(); 

	int mx = 0;

	for (int i = 0; i <= (int) s.length() - 10; i++)
		{
			date t = get_date(s, i);

			if (t.check())
				{
					m[t] ++;

					if (m[t] > mx)
						{
							mx = m[t];
							ans = t;
						}
				}
		}

	if (ans.d < 10)
		cout << 0;

	cout << ans.d << '-';

	if (ans.m < 10)
		cout << 0;

	cout << ans.m << '-' << ans.y;

	return 0;
}
