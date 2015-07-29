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
#define ll long long

map <int, bool> used;

int n, k;

VI a;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> k;

	a.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
		{
			cout << 1 << ' ' << a[i] << endl;;
			k--;
			if (!k)
				exit(0);
		}

	vector <int> tmp;

	for (; n;)
		{

			tmp.push_back(a[n - 1]);

			a.erase(a.end() - 1);
			n--;

			int cnt = tmp.size();
			
			for (int j = 0; j < n; j++)
				{

					cout << cnt + 1 << ' ';

					for (int i = 0; i < cnt; i++)
						cout << tmp[i] << ' ';

					cout << a[j];
					cout << endl;

			
					k--;

					if (!k)
						return 0;
			  }
		 }
				
	return 0;
}

