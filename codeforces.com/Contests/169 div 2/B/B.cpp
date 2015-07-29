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

	string s;

	cin >> s;

	int a[26] = {0};

	for (int i = 0; i < (int)s.size(); i++)
		a[s[i] - 'a']++;

	int cnt = 0;

	for (int i = 0; i < 26; i++)
		cnt += (a[i] % 2);

	if (cnt <= 1)
		cout << "First";
	else
		{
			if (cnt % 2)
				cout << "First";
			else
				cout << "Second";
		}

	return 0;
}
