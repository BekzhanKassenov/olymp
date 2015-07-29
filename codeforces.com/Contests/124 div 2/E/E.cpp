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

vector <vector <int> > g;

vector <PII> a;

vector <int> sz;

vector <pair <double, int> > angle;

vector <pair <int, int> > crd;

vector <int> ans;

int n;

void init()
{
	g.resize(n);
	a.resize(n);
	sz.resize(n);
	ans.resize(n);
	angle.resize(n);
	crd.resize(n);

	for (int i = 0; i < n; i++)
		angle[i].S = i;
}

void dfs(int v, int pr = -1)
{
	sz[v] = 1;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			if (g[v][i] != pr)
				{
					dfs(g[v][i], v);
					sz[v] += sz[g[v][i]];
				}
		}
}

void solve(int v, int l, int r, int pr = -1)
{
	if (l == r)
		{
			ans[v] = angle[l].S;
			return;
		}

	int anss = -1;

	for (int i = l; i <= r; i++)
		{
			if (anss == -1 || crd[angle[i].S].F < crd[angle[anss].S].F 
			    || (crd[angle[i].S].F == crd[angle[anss].S].F && crd[angle[i].S].S < crd[angle[anss].S].S))
			    	anss = i;
		}

	swap(angle[l], angle[anss]);

	ans[v] = angle[l].S;

	for (int i = l + 1; i <= r; i++)
		{
			angle[i].F = atan2(crd[angle[i].S].S - crd[angle[l].S].S, crd[angle[i].S].F - crd[angle[i].S].F);
		}

	sort(angle.begin() + l + 1, angle.begin() + r + 1);
	reverse(angle.begin() + l + 1, angle.begin() + r + 1);

	cout << v << " : ";

	cout << "ans = " << ans[v] << endl;

	for (int i = l + 1; i <= r; i++)
		cout << angle[i].S + 1 << ' ';

	l++;

	cout << endl << endl;	

	for (size_t i = 0; i < g[v].size(); i++)
		{
			if (g[v][i] != pr)
				{
					solve(g[v][i], l, l + sz[g[v][i]] - 1, v);
					l += sz[g[v][i]];
				}
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;

	init();
	
	for (int i = 0; i < n - 1; i++)
		{
			int x, y;

			cin >> x >> y;

			g[--x].push_back(--y);
			g[y].push_back(x);
		}

	for (int i = 0; i < n; i++)
		cin >> crd[i].F >> crd[i].S;

	dfs(0);

	solve(0, 0, n - 1);

	vector <int> anss(n, 0);

	for (int i = 0; i < n; i++)
		anss[ans[i]] = i;

	for (int i = 0; i < n; i++)
		cout << anss[i] + 1 << ' ';

	return 0;
}
