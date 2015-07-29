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
		freopen("out", "w", stdout);
	#endif

	int n, k;

	cin >> n >> k;

	if (n < k * 3 || k == 1)
		{
			puts("-1");
			return 0;
		}

	for (int i = 0; i < k; i++)
		printf("%d ", i + 1);

	for (int i = k; i >= 1; i--)
		printf("%d ", i);

	vector <int> a(k);

	for (int i = 0; i < k; i++)
		a[i] = i + 1;

	for (int i = 0; i < k; i +=	2)
		{
			if (i != k - 1)
				swap(a[i], a[i + 1]);
		}

	for (int i = 0; i < k; i++)
		printf("%d ", a[i]);

	for (int i = 3 * k; i < n; i++)
		printf("1 ");

	return 0;
}
