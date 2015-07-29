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
#define ull unsigned long long
#define INF
#define MOD
#define EPS
#define File ""

bool can(int a, int b)
{
	return (!((a + b) & 1) && a <= b);
}

int main()
{
   #ifndef ONLINE_JUDGE
   	freopen("in", "r", stdin);
   #endif

	int ans = 0;

	int a, b;

	cin >> a >> b;

	if (a > b || (b - a == 1))
		{
			cout << -1;
			return 0;
		}

	cout << ((b - a) >> 1);

	return 0;
}

