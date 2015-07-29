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
#define ull unsigned long long
#define int long long
#define MOD 777777777

struct ver
{
	int dp[4][4];
	ver()
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					dp[i][j] = 0;
		}
};

vector <ver> tree;
vector <int> a;

int can[4][4];

void gr(int cnt, int &l, int &r)
{
	if (cnt == 0)
		l = 1, r = 3;
	else
		l = r = cnt;	
}

void dyn(int v, int l, int r)
{
	int m = (l + r) >> 1;
	int lb, le, rb, re, mb, me, mpb, mpe;

	gr(a[l], lb, le);
	gr(a[r], rb, re);
	gr(a[m], mb, me);
	gr(a[m + 1], mpb, mpe);

	if (r - l > 1)
		{
			for (int _l = lb; _l <= le; _l ++)
				for (int _r = rb; _r <= re; _r ++)
					for (int _m = mb; _m <= me; _m++)
						for (int _mp = mpb; _mp <= mpe; _mp++)
							if (can[_m][_mp])
								{
									tree[v].dp[_l][_r] += (tree[2 * v].dp[_l][_m] * tree[2 * v + 1].dp[_mp][_r]) % MOD;
									tree[v].dp[_l][_r] %= MOD;
      						}

      }
   else
   	{
   		if (r - l == 1)
   			{	for (int _l = lb; _l <= le; _l++)
   					for (int _r = rb; _r <= re; _r++)
   						if (can[_l][_r])
   							tree[v].dp[_l][_r] = 1;
   		  	}
   		if (l == r)
   			{
   				for (int _l = lb; _l <= le; _l++)
   					tree[v].dp[_l][_l] = 1;
   			}                                 
   	}

}

void update(int v, int l, int r, int ind)
{
	if (ind > r || ind < l)
		return;

	if (l > r)
		return;

	int m = (l + r) >> 1;

	tree[v] = ver();

	if (l == r)
		{
			dyn(v, l, r);
			return;
		}

	update(2 * v, l, m, ind);

	update(2 * v + 1, m + 1, r, ind);

	dyn(v, l, r);

}

int get_ans()
{
	int ans = 0;

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			{
				ans += tree[1].dp[i][j];
				ans %= MOD;
			}

	 return ans;
}

main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	int n, m;

	scanf("%I64d%I64d", &n, &m);

	a.resize(n + 1);

	tree.resize(4 * n + 1);

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			{
				scanf("%I64d", &can[i][j]);
			}

	for (int i = 1; i <= n; i++)
		update(1, 1, n, i);

	for (int i = 0; i < m; i++)
		{
			int t, v;

			scanf("%I64d%I64d", &t, &v);

			a[t] = v;

			update(1, 1, n, t);

			printf("%I64d\n", get_ans());
		}

}
