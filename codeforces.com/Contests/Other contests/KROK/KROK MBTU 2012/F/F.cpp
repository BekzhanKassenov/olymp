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
#define all(x) (x).begin(), (x).end()

int sum[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

int get_date(const char* s) {
	int n, res = 0;
	    
	res = (s[5] - '0') * 10 + (s[6] - '0');

	n = (s[8] - '0') * 10 + s[9] - '0';
	res = sum[res - 1] + n;

	n = (s[11] - '0') * 10 + s[12] - '0';
	res = res * 24 + n;

	n = (s[14] - '0') * 10 + s[15] - '0';
	res = res * 60 + n;

	n = (s[17] - '0') * 10 + s[18] - '0';
	res = res * 60 + n;

	return res;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	string s;

	getline(cin, s);

	vector <int> a;

	while (getline(cin, s)) {
		int cur = get_date(s.c_str());

		int t = cur - n + 1;

		int pos = lower_bound(all(a), t) - a.begin();

		if ((int)a.size() - pos + 1 >= m) {
			cout << s.substr(0, 19);
			return 0;
		}

		a.push_back(cur);
	}

	cout << -1;

	return 0;
}
