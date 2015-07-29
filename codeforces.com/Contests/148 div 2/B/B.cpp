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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	string str;

	int n, q;

	cin >> n >> q;

	cin >> str;

	for (int i = 0; i < q; i++)
		{
			int l, r;

			cin >> l >> r;

			l--, r--;

			int a[10] = {0};

			string s = str.substr(l, (r - l) + 1);

			int cp = 0, dp = 1;

			for (;;)
				{
					if (s[cp] <= '9' && s[cp] >= '0')
						{
							a[s[cp] - '0'] ++;
							if (s[cp] == '0')
								{
									s.erase(s.begin() + cp);
									if (dp == -1)
										cp--;
								}
							else
								{
									s[cp]--;	
									cp += dp;
								}
							if (cp < 0 || cp >= (int)s.length())
								break;
							continue;
						}
					if (s[cp] == '>' || s[cp] == '<')
						{
							if (s[cp] == '>')
								dp = 1;
							else
								dp = -1;

							if (s[cp + dp] == '>' || s[cp + dp] == '<')
								{
									s.erase(s.begin() + cp);
									if (dp == -1)
										cp--;
								}
							else
								cp += dp;
						}
					if (cp < 0 || cp >= (int)s.length())
						break;
				}

		 	for (int i = 0; i < 10; i++)
		 		{
		 			cout << a[i] << ' ';
		 		}
		 	cout << endl;
		}

	return 0;
}
