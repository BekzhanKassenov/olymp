/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>


using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 2000000000
#define EPS 10e-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define VI vector <int>

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	string s;
	cin >> s;
	
	int n = (int)s.length();

	stack <int> st;

	VI a(n, -1);

	for (int i = 0; i < n; i++)
		{
			if (s[i] == '(' || s[i] == '[')
				st.push(i);
			if (s[i] == ')')
				{
					if (st.empty())
						continue;
					int k = st.top();
					st.pop();
					if (s[k] == '(')
						{
							a[k] = i;
							a[i] = k;
						}
					else
						{
							while (!st.empty())
								st.pop();
						}
				}
			if (s[i] == ']')
				{
					if (st.empty())
						continue;
					int k = st.top();
					st.pop();
					if (s[k] == '[')
						{
							a[k] = i;
							a[i] = k;
						}
					else
						while (!st.empty())
								st.pop();
				}

		}
	int l = -1, r = -1, cnt = 0, i = 0;
	while (i < n)
		{
			int tl = i, _t = i, c = 0;
			if (a[i] == -1)
				{
					i++;
					continue;

				}
			while (a[i] != -1 && i < n)
				{
					if (s[i] == '[')
						c++;
					_t++;
					i++;
				}
			//cout << c << ' ' << tl << ' ' << _t << endl;
			if (c > cnt || (c == cnt && (_t - tl) > (r - l)))
				{
					r = _t;
					l = tl;
					cnt = c;
				}
		}
	cout << cnt << endl;
	if (cnt != 0)
		cout << s.substr(l, (r - l));;

	return 0;
}
