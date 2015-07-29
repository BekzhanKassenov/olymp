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
#define ull unsigned long long
#define ll long long

const ll MOD = (1000 * 1000 * 1000 + 7);

ll bin_pow(ll n, int st) {
	if (st == 0)
		return 1;

	if (st & 1) {
		return (bin_pow(n, st - 1) * n) % MOD;
	} else {
		ll b = bin_pow(n, st >> 1);
		return (b * b) % MOD;
	}	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	int cnt = 0;

	string s, t;

	cin >> s >> t;

	bool flag1 = false, flag2 = false;

	for (int i = 0; i < n; i++) {
		cnt += (s[i] == '?');
		cnt += (t[i] == '?');

		if (s[i] != '?' && t[i] != '?') {
			if (s[i] < t[i])
				flag1 = true;

			if (s[i] > t[i])
				flag2 = true;
	   	}
	}

	ll whole = bin_pow(10, cnt);

	if (flag1 && flag2) {
		cout << whole;
		return 0;
	}

	if (flag2)
		swap(s, t);

	ll good = 1;

	for (int i = 0; i < n; i++) {
		if (s[i] == '?' && t[i] == '?')
			good = (good * 45ll) % MOD;
		
		if (s[i] == '?' && t[i] != '?')
			good = (good * (t[i] - '0' + 1ll)) % MOD;
			
		if (s[i] != '?' && t[i] == '?')	
			good = (good * (10ll - (s[i] - '0'))) % MOD;	
	}

	cout << (whole - good + MOD) % MOD;

	return 0;
}
