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
#define VI vector <int>
#define LL long long
#define ULL unsigned long long

bool check(string s, int pr, int len)
{
	for (int i = pr; i < len; i++)
		if (s[i] != s[i - pr])
			return false;

	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	string a, b;

	cin >> a >> b;

	int lena = (int)a.length();

	int lenb = (int)b.length();

	set <string> q;

	int k = sqrt(lena);

	for (int i = 1; i <= k; i++)
		{
			if (lena % i == 0)
				{
					if (check(a, i, lena))
						q.insert(a.substr(0, i));

					if (check(a, lena / i, lena))
						q.insert(a.substr(0, lena / i));
				}
		}

	k = sqrt(lenb);

	int ans = 0;

	for (int i = 1; i <= k; i++)
		{
			if (lenb % i == 0)
				{
					if (check(b, i, lenb) && q.find(b.substr(0, i)) != q.end())
						ans++;
					if (i * i != lenb)
						if (check(b, lenb / i, lenb) && q.find(b.substr(0, lenb / i)) != q.end())
							ans++;
				}
		}
	cout << ans;
	return 0;
}
