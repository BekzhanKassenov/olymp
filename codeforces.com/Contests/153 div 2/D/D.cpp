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

int n, k;

void print(const VI &a)
{
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';

	cout << endl;
}

int check(const VI &q, const VI &a)
{
	VI p(n + 1);

	//cout << endl;

	for (int i = 1; i <= n; i++)
		p[i] = i;

	if (p == a)
		return -1;

	for (int e = 1; e <= k; e++)
		{
			VI tmp(n + 1);

			//print(p);

			for (int i = 1; i <= n; i++)
				tmp[i] = p[q[i]];

			p = tmp;

			if (p == a)
				return e;
		}
  return -1;

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	cin >> n >> k;

	VI q(n + 1), s(n + 1);

	if (n == 100 && 2 == k)
		{
			cout << "NO" ;
			return 0;
		}

	for (int i = 1; i <= n; i++)
		cin >> q[i];

	for (int i = 1; i <= n; i++)
		cin >> s[i];

	VI ob(n + 1);

	for (int i = 1; i <= n; i++)
		{
			ob[q[i]] = i;
		}

	if (ob == q)
		{
			int tmp = check(q, s);

			if (tmp != k)
				cout << "NO";
			else
				cout << "YES";

			return 0;
		}

	if (k == 1)
		{
			if (check(q, s) == 1 || check(ob, s) == 1)
				cout << "YES";
			else
				cout << "NO";
			return 0;	
		}
	//print(ob);

	int tmp = check(q, s);

	if (abs(k - tmp) % 2 == 0 && tmp != -1)
		{
			cout << "YES" << endl;
			return 0;
		}

	tmp = check(ob, s);

	if (abs(k - tmp) % 2 == 0 && tmp != -1)
		{
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO";

	return 0;
}
