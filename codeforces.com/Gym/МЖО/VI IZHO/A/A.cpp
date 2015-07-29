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
#define File "document"

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;
	
	cin >> n;

	int a[7];

	int cur = 0;

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 5; j++)
				cin >> a[j];

			while (a[cur] != 1)
				{
					cur++;
					ans++;

					if (cur == 7)
						cur = 0;
				}

		 	cur++;

		 	if (cur == 7)
		 		cur = 0;
		 	ans++;
		}

	cout << ans;

	return 0;
}
