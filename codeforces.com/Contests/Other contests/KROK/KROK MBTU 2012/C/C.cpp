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

int n;

VI a;

int ans = (1 << 25);

map <vector <int>, int> clc;

int rec(int gl)
{
	//cout << gl << endl;
	int &ans = clc[a];
	if (ans != 0)
		return ans;

	ans = (1 << 25);

	bool flag = true;
	for (int i = 1; i <= n; i++)
		if (a[i] != 0)
			{
				flag = false;
				break;
			} 
	if (flag)
		{
			ans = min(ans, gl);
			return ans; 
		}

	for (int x = 1; 2 * x + 1 <= n; x++)
		{
			bool flag1 = false, flag2 = false, flag3 = false;
			if (a[x] > 0)
				{
					a[x]--;
					flag1 = true;
				}

			if (a[2 * x] > 0)
				{
					a[2 * x]--;
					flag2 = true;
				}

			if (a[2 * x + 1] > 0)
				{
					a[2 * x + 1]--;
					flag3 = true;
				}

			ans = min(ans, rec(gl + 1));

			if (flag1)
				a[x] ++;

			if (flag2)
				a[2 * x]++;

			if (flag3)
				a[2 * x + 1]++;
		
		}

	return ans;	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);

	#endif

	cin >> n;

	a.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int ans = rec(0);

	if (ans !=  (1 << 25))

		cout << ans;

	else
		cout << -1;


	return 0;
}
