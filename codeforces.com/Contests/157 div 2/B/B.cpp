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

int a[3][3];

bool check()
{
	int sum = a[0][0] + a[0][1] + a[0][2];

	int tmp = a[1][0] + a[1][1] + a[1][2];

	if (tmp != sum)
		return false;

	tmp = a[2][0] + a[2][1] + a[2][2];

	if (tmp != sum)
		return false;

	tmp = a[0][0] + a[1][0] + a[2][0];

	if (tmp != sum)
		return false;

	tmp = a[0][1] + a[1][1] + a[2][1];

	if (tmp != sum)
		return false;

	tmp = a[0][2] + a[1][2] + a[2][2];

	if (tmp != sum)
		return false;

	tmp = a[0][0] + a[1][1] + a[2][2];

	if (tmp != sum)
		return false;

	tmp = a[0][2] + a[1][1] + a[2][0];

	if (tmp != sum)
		return false;

	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];

	for (int q = 1; q <= 100000; q++)
		{
			a[0][0] = q;

			int sm = a[0][0] + a[1][0] + a[2][0];

			a[1][1] = sm - a[1][0] - a[1][2];

			a[2][2] = sm - a[2][0] - a[2][1];

			if (a[1][1] <= 0 || a[2][2] <= 0)
				continue;

			if (check())
				{
					for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
								cout << a[i][j] << ' ';

							cout << endl;	
						}

					break;
				}
		}

	return 0;
}
