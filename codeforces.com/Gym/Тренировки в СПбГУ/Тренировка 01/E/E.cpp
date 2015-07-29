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
#define File "strings"

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	string s, t;

	cin >> s >> t;

	int tlen = t.length();

	s = t + '#' + s;

	int len = s.length();

	vector <int> p(len);

	p[0] = 0;

	for (int i = 1; i < len; i++)
		{
			int j = p[i - 1];

			while (s[i] != s[j] && j > 0)
				j = p[j - 1];

			if (s[i] == s[j])
				j++;

			p[i] = j;
		}

	bool flag = false;

	for (int i = 0; i < len; i++)
		{
			if (p[i] == tlen)
				{
					flag = true;
					cout << i + 1 - 2 * tlen << ' ';
				}
		}

	if (!flag)
		cout << "none";

	return 0;

}
