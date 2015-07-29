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
#define SZ size()
#define VI vector <int>

int a[1010][1010];

int r[1010], c[1010];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m, k;

	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	
			scanf("%d", &a[i][j]);

	for (int i = 0; i < n; i++)
		r[i] = i;

	for (int j = 0; j < m; j++)
		c[j] = j;

	char ch;

	int x, y;

	while (k--)
		{
			scanf("\n%c%d%d", &ch, &x, &y);

			y--, x--;

			if (ch == 'g')
				{
					printf("%d\n", a[r[x]][c[y]]);
				}

			if (ch == 'r')
				swap(r[x], r[y]);

			if (ch == 'c')
				swap(c[x], c[y]);
		}

 	return 0;
}



