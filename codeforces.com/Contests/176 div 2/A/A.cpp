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

	char c;

	int a[4][4];

	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				{
					cin >> c;

					if (c == '#')
						a[i][j] = 1;
					else
						a[i][j] = 0;	
				}
		}

	for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
				{
					int s = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];

					if (s != 2)
						{
							cout << "YES";
							return 0;
						}
				}
		}

	cout << "NO";

	return 0;
}
