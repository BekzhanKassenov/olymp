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

int cnt(const string& a, const string& b, int pos)
{
	int len = b.size();

	int ans = 0;

	for (int i = 0; i < len; i++)
		if (b[i] != a[i + pos])
			ans++;

   	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s, t;

	cin >> s >> t;

	for (int i = 0; i < (int)t.size(); i++)
		s = " " + s + " ";

	int ans = INF;

	for (size_t i = 0; i < s.size(); i++)
		ans = min(ans, cnt(s, t, i));

	cout << ans;	

	return 0;
}
