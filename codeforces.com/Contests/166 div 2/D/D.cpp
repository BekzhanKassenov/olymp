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

const int base = 59;

const int MOD = (1000 * 1000 * 1000 + 9);

const int base1 = 37;

const int MOD1 = (1000 * 1000 * 100 + 7);

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	string s;

	cin >> s;

	string good;

	cin >> good;

	int k;

	cin >> k;

	int n = s.length();

	vector <int> st(n), st1(n);

	st[0] = 1;
	st1[0] = 1;

	for (int i = 1; i < n; i++)
		{
			st[i] = (st[i - 1] * 1ll * base) % MOD;
			st1[i] = (st1[i - 1] * 1ll * base1) % MOD;
		}

	map <long long, int> m;

	for (int i = 0; i < n; i++)
		{
			int hs = 0, hs1 = 0;

			int cnt = 0;               

			for (int j = i; j < n; j++)
				{
					hs = (hs + (s[j] * 1ll * st[j - i]) % MOD) % MOD;

					hs1 = (hs1 + (s[j] * 1ll * st1[j - i]) % MOD1) % MOD1;
					
					if (good[s[j] - 'a'] == '0')
						cnt++;

					if (cnt > k)
						break;

					long long h = hs;

					h <<= 32;
					h += hs1;

					m[h]++;
				}
		}

	cout << m.size() << endl;	

	return 0;
}
