/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	set <int> s;

	int tmp;

	while (cin >> tmp)
		{
			s.insert(tmp);
		}

	vector <int> a(s.begin(), s.end());

	n = s.size();

	VI b(n);

	for (int i = 0; i < n; i++)
		{
			b[i] = a[i] * a[i];
			//cout << a[i] << ' ' << b[i] << endl;
		}

		//cout << endl;
	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				{
					int p1 = upper_bound(b.begin(), b.end(), b[i] + b[j]) - b.begin();
					int p2 = lower_bound(a.begin(), a.end(), a[i] + a[j]) - a.begin();

					if (a[p2] == a[i] + a[j])
						{
							if (p2 == 0)
								continue;

							p2--;	
						}

					//cout << a[i] << ' ' << a[j] << endl;
					if (p2 >= p1 && p1 > j && p2 != n && p1 != n)
						ans += p2 - p1 + 1;
				}
		}
	
	cout << ans;
	return 0;
}
