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

vector <int> intersect(const vector <int> &a, const vector <int> &b)
{
	vector <int> ans;

	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				if (a[i] == b[j])
					ans.push_back(a[i]);
		}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <vector <int> > a(n + 1);

	for (int i = 0; i < 2 * n; i++)
		{
			int c, b;

			scanf("%d%d", &c, &b);

			a[c].push_back(b);
			a[b].push_back(c);
		}

	if (n <= 8)
		{
			vector <int> ans(n + 1, 0);

			for (int i = 1; i <= n; i++)
				ans[i] = i;

			do
				{
					vector <vector <int> > tmp(n + 1, vector <int> (4));

					for (int i = 1; i <= n; i++)
						{
							int k = i - 2;

							if (k < 1)
								k += n;

							tmp[i][0] = a[k];

							k = i - 1;

							if (k < 1)
								k += n;

							tmp[i][1] = a[k];

							k = i + 1;

							if (k > n)
								k -= n;

							tmp[i][2] = a[k];

							k = i + 2;

							if (k > n)
								k -= n;

							tmp[i][3] = a[k];	
							sort(tmp[i].begin(), tmp[i].end());
						}

					if (
				}
			while (next_permutation(ans.begin() + 1, ans.end()));
		}

	vector <bool> used(n + 1, 0);

	vector <int> ans(n + 1);

	for (int i = 0; i < 4; i++)
		{
			vector <int> tmp = intersect(a[a[1][i]], a[1]); 

			if (tmp.size() >= 2)
				{
					ans[1] = a[1][i];
					used[a[1][i]] = true;
					break;
				}

			
			   cout << 1 << ' ' << a[1][i] << endl;

			   for (int j = 0; j < (int)tmp.size(); j++)
			   	cout << tmp[j] << ' ';
			   	cout << endl;
			for (int j = 0; j < 4; j++)
				cout << a[a[1][i]][j] << ' ';

			cout << endl;
		}

	for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < 4; j++)
				{
					vector <int> tmp = intersect(a[a[i][j]], a[i]);

					if (tmp.size() >= 2 && !used[a[i][j]])
						{
							ans[i] = a[i][j];
							used[a[i][j]] = true;
					   }
				}
		}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';

	return 0;
}
