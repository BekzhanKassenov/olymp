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

int n;

void pp(vector <int> &a)
{
	for (int i = 0; i < n; i++)
		{
			a[i]++;
			if (a[i] == 10)
				a[i] = 0;
			else
				break;
		}
}

int mod(vector <int> &a, int m)
{
	int ans = 0;

	for (int i = n - 1; i >= 0; i--)
		ans = (ans * 10 + a[i]) % m;

	return ans;
}

void print(vector <int> &a)
{
	for (int i = n - 1; i >= 0; i--)
		cout << a[i];

	cout << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	cin >> n;

	if (n == 1 || n == 2)
		{
			cout << -1;
			return 0;
		}

	vector <int> a(n);

	a[n - 1] = 1;

	int md = 210;

	for (int i = 0; i < md; i++)
		{
			int q = mod(a, md);

			/*cout << q << "------->";

			print(a); */
			if (q == 0)
				{
					print(a);
					return 0;
				}

			pp(a);
		}

	return 0;
}
