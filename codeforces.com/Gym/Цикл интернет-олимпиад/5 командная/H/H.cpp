/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS
#define File "versus"

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	scanf("%d", &n);

	long long ans = 0;

	int q[2] = {0, 0};

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a.begin(), a.end());

	q[a[0] & 1]++;

	for (int i = 1; i < n; i++)
		{
			q[a[i] & 1]++;

		}

	ans = q[0] * 1ll * q[1];
	
	printf("%I64d", ans);
	return 0;
}
