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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	VI a(n), b(n), c(n);

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[i] = a[i];
			c[i] = a[i];
		}

	sort(b.begin(), b.end());

	sort(c.rbegin(), c.rend());
	
	if (b[0] == b[n - 1])
		{
			cout << -1;
			return 0;
		}

	if (n == 1 || n == 2)
		{
			cout << -1;
			return 0;
		}

	srand(time(0));

	int cnt = 5;

	set <PII> st;

	while (cnt)
		{
			int l = rand() % n;
			int r = rand() % n;

			if (l > r)
				swap(l, r);

			if (st.find(MP(l, r)) != st.end())
				continue;

			if (a[l] == a[r]) 
				{
					st.insert(MP(l, r));
					continue;
				}

			st.insert(MP(l, r));

			if (st.size() == ((n * (n - 1)) / 2))
				break;

			swap(a[l], a[r]);

			bool s1 = true, s2 = true;

			for (int i = 1; i < n; i++)
				{
					if (a[i] > a[i - 1])
						s2 = false;

					if (a[i] < a[i - 1])
						s1 = false;
		     	}

		   cnt--;

		   if (s1 || s2)
		   	{
		   		swap(a[l], a[r]);
		   		continue;
		   	}

		   cout << l + 1<< ' ' << r + 1;
		   return 0;	

		}

	cout << -1;	
	return 0;
}
