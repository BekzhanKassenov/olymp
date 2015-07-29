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
#define EPS 1e-14

string s;

int n;

void rec(int cnt)
{
	if (cnt > n)
		return;

	if (s[cnt - 1] == 'l')
		{
			rec(cnt + 1);
			cout << cnt << endl;
		}
	else
		{
			cout << cnt << endl;
			rec(cnt + 1);
		}	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	cin >> s;

	n = s.length();
	
	rec(1);

	return 0;
}
