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
#define EPS 1e-1
#define File "chaotic" 

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <int> ans;

	for (int i = 1; i < n - 1; i++)
		{
			if (a[i - 1] > a[i] && a[i] > a[i + 1])
				{
					ans.push_back(i);
					swap(a[i], a[i + 1]);
				}
			if (a[i - 1] < a[i] && a[i] < a[i + 1])
				{
					ans.push_back(i);
					swap(a[i], a[i + 1]);
				}
		}

	if ((int)ans.size() > n)
		{
			cout << -1;
			return 0;
		}

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] + 1 << ' ' ;


	return 0;
}
