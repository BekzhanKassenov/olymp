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

vector <int> t;

vector <int> a;

vector <vector <int> > pows;

int n, m;

void calc()
{
	pows[1][0] = pows[1][1] = pows[1][2] = pows[1][3] = pows[1][4] = pows[1][5] = 1;

	for (int i = 2; i <= n; i++)
		{
			long long tmp = 1;

		  	for (int j = 0; j <= 5; j++)
		  		{
		  			pows[i][j] = (pows[i - 1][j] + tmp) % MOD;
		  			tmp = (tmp * i) % MOD;
		  		}
		}
}

void build(int v, int l, int r)
{
	if (l > r)
		return;

	if (l == r)
		{
			t[v] = a[l];
			return;
		}

  	int m = (l + r) >> 1;

  	build(v << 1, l, m);

  	build((v << 1) + 1, m + 1, r);

  	if (t[v << 1] != -1 && t[(v << 1) + 1] != -1 && t[(v << 1)] == t[(v << 1) + 1])
  		t[v] = t[v << 1];
}

void push(int v)
{
	if (t[v] != -1)
		{
			t[v << 1] = t[v];
			t[(v << 1) + 1] = t[v];
		}
}

void upd(int v, int cur_l, int cur_r, int l, int r, int val)
{
	if (cur_l > cur_r)
		return;

	if (cur_l == cur_r)
		{
			if (cur_l <= r && cur_r >= l)
				{
					t[v] = val;
					a[cur_l] = val;
				}

			return;
		}

	if (cur_l >= l && cur_r <= r)
		{
			t[v] = val;
			return;
		}

	int m = (cur_l + cur_r) >> 1;

	push(v);

	upd(v << 1, cur_l, m, l, r, val);
	upd((v << 1) + 1, m + 1, cur_r, l, r, val);
 
   if (t[v << 1] != -1 && t[(v << 1) + 1] != -1 && t[(v << 1)] == t[(v << 1) + 1])
  		t[v] = t[v << 1];
  	else
  		t[v] = -1;
}

int get_ans(int v, int cur_l, int cur_r, int l, int r, int k)
{
	if (cur_l > cur_r)
		return 0;

	//cout << cur_l << ' ' << cur_r << ' ' << l << ' ' << r << endl;

	long long ans = 0;

	if (cur_l == cur_r)
		{
			if (cur_l <= r && cur_l >= l)
				ans += (t[v] * 1ll * pows[1][k]) % MOD;
			
			return ans;
		}

	if (cur_l >= r || cur_r <= l)
		return 0;

	if (cur_l >= l && cur_r <= r && t[v] != -1)
		{
			ans = (t[v] * 1ll * ((pows[cur_r][k] - pows[cur_l][k] + MOD) % MOD) % MOD);
			return ans;
		}

	int m = (cur_l + cur_r) >> 1;

	push(v);

	ans += get_ans((v << 1), cur_l, m, l, r, k);
	ans = (ans + get_ans((v << 1) + 1, m + 1, cur_r, l, r, k)) % MOD;
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d", &n, &m);

	a.resize(n);
	t.resize(4 * n);
	pows.resize(n + 1, vector <int>(6));

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	calc();

	build(1, 0, n - 1);

	char c;
	
	int l, r, k;
	
	for (int i = 0; i < m; i++)
		{
		   cin >> c >> l >> r >> k;

			l--, r--;

			cout << c << ' ' ;

			if (c == '?')
				{
					printf("%d\n", get_ans(1, 0, n - 1, l, r, k));
				}
			else
				{
					upd(1, 0, n - 1, l, r, k);
				}

			//cout << "OK" << endl;	
		}

	return 0;
}
