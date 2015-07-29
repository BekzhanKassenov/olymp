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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	scanf("%d", &n);

	n *= 2;

	vector <vector <int> > a(5020);

	for (int i = 0; i < n; i++)
		{
			int tmp;

			scanf("%d", &tmp);
			
			a[tmp].push_back(i + 1);
		}

	bool flag = true;

	for (int i = 1; i <= 5000; i++)
		{
			if (!a[i].empty())
				{
					if (a[i].size() % 2 != 0)
						{
							flag = false;
							break;
						}
				}
		}

	if (!flag)
		{
			cout << -1;
			return 0;
		}
			
	for (int i = 1; i <= 5000; i++)
		{
			int pos = 0;

			if (a[i].empty())
				continue;

			while (pos < (int)a[i].size())
				{
					printf("%d %d\n", a[i][pos], a[i][pos + 1]);
					pos += 2;
				}
		}
	return 0;
}
