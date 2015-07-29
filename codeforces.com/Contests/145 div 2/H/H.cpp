/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 2000000000
#define EPS 10e-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define LL long long
#define ULL unsigned long long

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;

	scanf("%d", &n);

	vector <bool> a(n);

	int tmp;

	for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);

			a[i] = tmp;
		}

	scanf("%d", &m);

	vector <int> b(m);

	for (int i = 0; i < m; i++)
		{
			scanf("%d", &tmp);

			b[i] = tmp;
		}

	int p1 = 0, p2 = 0;

	vector <int> ans;

	for (;;)
		{
			
		}
	return 0;
}

