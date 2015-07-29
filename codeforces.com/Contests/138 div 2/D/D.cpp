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

	string t;
	cin >> t;

	int n = (int)s.length();

	int len = (int)t.length();

	vector <int> l(n), r(n);


	vector <vector <int> > cnt(n, vector <int> (27));

	for (int i = 1; i < len; i++)
		{
			for (char j = 'a'; j <= 'z'; j++)
				{
					a[i][j - 'a'] = a[i - 1][j - 'a'];
					if (t[i] == j)	
				}
		}

	return 0;
}
