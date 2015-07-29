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

int a[26] = {0};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++)
		a[s[i] - 'a']++;
	
	string ans;
	
	for (int i = 0; i < 26; i++)
		{
			if (a[i] != 0)
				{
					if (a[i] % n != 0)
						{
							cout << -1;
							return 0;
						}
					else
						for (int j = 0; j < (a[i] / n); j++)
							ans += char(i + 'a');
				}
	   }
	for (int i = 0; i < n; i++)
		cout << ans;
	cout << endl;
	return 0;

}
