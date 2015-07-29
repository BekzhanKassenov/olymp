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

int a[6000] = {0};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int tmp = 0;

	set <int> s;

	for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			a[tmp]++;
			s.insert(tmp);
		}

	int ans = INF;

	vector <int> q (s.begin(), s.end());

	n = q.size();

	for (int i = 0; i < n; i++)
		{
			int tmp = 0;

			vector <int> :: iterator it = upper_bound(q.begin(), q.end(), q[i] * 2);

			int pos = (int)(it - q.begin());

			//cout << pos << endl;	

			if (it != q.end())
				{
				   for (int t = 0; t < i; t++)
				   	tmp += a[q[t]];

				   for (int t = pos; t < n; t++)
				   	tmp += a[q[t]];

				   //cout << i << ' ' << pos << endl;

				   //cout << tmp << endl;
					
					ans = min(ans, tmp);
				}

			else
				{
					for (int t = 0; t < i; t++)
						tmp += a[q[t]];

					ans = min(ans, tmp);
				}	

		}

	cout << ans;
	return 0;
}
