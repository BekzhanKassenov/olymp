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
	int s, k;
	cin >> s >> k;

	VI a (1000000, 0);

	a[0] = 1;
	a[1] = 1;
	if (s == 1)
		{
			cout << 2 << endl << 1 << ' ' << 0;
			return 0;
		}
	int n = 2;
	for (int i = 2; a[i - 1] < s; i++)
		{
			a[i] = (a[i - 1] - ((i - k - 1 >= 0) ? (a[i - k - 1]) : (0))) + a[i - 1];
			if (a[i] == s)
				{
					cout << 2 << endl << 0 << ' ' << s;
					return 0;
				}
			//cout << a[i] << ' ';
			n++;
		}
	VI ans;
	for (int i = n - 1; i > 0; i--)
		{
			if (a[i] <= s)
				{
					ans.PB(a[i]);
					s -= a[i];
				}
		}
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}
