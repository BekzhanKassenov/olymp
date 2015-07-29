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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> ans;

	int now = 0;

	int cnt = 0;

	int x = 0;

	for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x >= 0)
				now++;

			if (x < 0)
				{
					cnt++;
					if (cnt >= 3)
						{
							cnt = 1;
							ans.push_back(now);
							now = 1;
						}
					else
						now++;
				}
		}

	ans.push_back(now);

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << ' ';

	return 0;
}
