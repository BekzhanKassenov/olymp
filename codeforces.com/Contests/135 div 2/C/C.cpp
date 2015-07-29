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

int n, k;

int ch(string a, string b)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			ans++;
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	cin >> n >> k;
	
	string s;
	cin >> s;

	if (k == 2)
		{
			string z;
			string m;
			z += 'A';
			for (int i = 1; i < n; i++)
				z += (z[i - 1] == 'A') ? 'B' : 'A';
			m += 'B';
			for (int i = 1; i < n; i++)
				m += (m[i - 1] == 'A') ? 'B' : 'A';
			
			if (ch(m, s) < ch(z, s))
				cout << ch(m, s) << endl << m << endl;
			else
				cout << ch(z, s) << endl << z << endl;
			
			return 0;
		}
	
	int ans = 0;

	for (int i = 1; i < n; i++)
		{
			if (s[i] == s[i - 1])
				{
					char j = 'A';
					while (j == s[i - 1] || j == s[i + 1])
						j++;
					s[i] = j;
					ans++;
				}
		}
	
	cout << ans << endl << s;
	return 0;
}

