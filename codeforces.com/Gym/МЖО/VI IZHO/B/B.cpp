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
#define File "monster"

const int MAXK = 3 * 1000 * 1000 * 10 + 1;

const int MAX_LOG = 25;

vector <int> primes;

int c[MAX_LOG][MAX_LOG];

void build()
{
	vector <bool> prime(MAXK, true);

	prime[0] = prime[1] = false;

	for (int i = 2; i <= MAXK; i++)
		{
			if (prime[i])
				{
					primes.push_back(i);

					if (i * 1ll * i <= MAXK)
						{
							for (int j = i * i; j <= MAXK; j += i)
								prime[j] = false;
						}
				}
		}
}

void calc_c()
{
	c[0][0] = 1;
	for (int i = 1; i < MAX_LOG; i++)
		{
			c[i][0] = c[i][i] = 1;

			for (int j = 1; j < i; j++)
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int k, n;

	scanf("%d%d", &k, &n);

	build();

	calc_c();

	return 0;
}
