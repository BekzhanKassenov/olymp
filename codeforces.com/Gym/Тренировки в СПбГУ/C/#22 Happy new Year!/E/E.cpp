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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	cin >> s;

	vector <pair <char, int> > a;

	int r, w;

	cin >> r >> w;

	for (int i = 0; i < (int)s.length(); i++)
		{
			if (a.empty() || a.back().F != s[i])
				a.push_back(MP(s[i], 1));
			else
				a.back().S++;
		}

	for (int i = 0; i < (int)a.size(); i++)
		{
			if (a[i].F == '
		}

	return 0;
}
