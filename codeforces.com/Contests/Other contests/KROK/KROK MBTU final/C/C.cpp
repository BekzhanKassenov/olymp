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

	int n, k;

	cin >> n >> k;

	vector <int> a;

	a.reserve(n);

	int uk = 0;

	int x;

	cin >> x;

	a.push_back(x);

	uk++;

	for (int i = 0; i < n; i++)
		{
			cin >> x;

			if (x != a[uk - 1])
				{
					a.push_back(x);
					uk++;
				}
		}

	vector <int> cnt (k + 1);

	cnt[a[0]]++;
	cnt[a[uk - 1]]++;

	/*for (int i = 0; i < uk; i++)
		cout << a[i] << ' ';

	cout << endl;*/

	for (int i = 1; i < uk - 1; i++)
		if (a[i - 1] == a[i + 1])
			cnt[a[i]] += 2;
		else
			cnt[a[i]] ++;

	int mx = 1;

	for (int i = 1; i <= k; i++)
		{
			if (cnt[i] > cnt[mx])
				mx = i;

			//cout << i << " ---> " << cnt[i] << endl;
		}

	cout << mx;

	return 0;
}
