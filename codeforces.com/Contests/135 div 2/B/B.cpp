/*********************************************
**       Solution by Bekjan Kasenov         **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 1000000000
#define EPS 10e-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define VI vector <int>
#define LL long long

string int_to_str(LL a)
{
	string ans;
	while (a)
		ans += a % 10, a /= 10;
	return ans;
}

LL str_to_int(string s)
{
	LL ans = 0;
	for (int i = s.length() - 1; i >= 0; i--)
		{
			ans *= 10;
			ans += s[i];
		}
	return ans;
	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	LL n, d;
	
	cin >> n >> d;

	string s = int_to_str(n);
	
	LL ans = -1;

	LL z = 0;

	LL m;

	while (s[z] == 9)
		s[z ++] = 0;

	m = z;

	for (int i = z; i < s.length(); i++)
		{
			s[i] = 0;
			LL temp = str_to_int(s);
			temp --;
			if (temp >= n - d && temp > 0 && i >= m)
				{
					ans = temp;
					m = i;
				}
		}

	if (ans != -1)
		cout << ans;
	else
		cout << n;
	return 0;
}
