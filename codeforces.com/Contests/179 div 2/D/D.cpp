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
	#endif

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	vector <vector <ll> > g(n, vector <ll> (n, INF));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	vector <int> x(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
		x[i]--;
	}

   	vector <ll> ans(n);

	for (int c = n - 1; c >= 0; c--) {
		ll sum = 0;

		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) {
				g[i][j] = min(g[i][x[c]] + g[x[c]][j], g[i][j]);
			}

		for (int i = c; i < n; i++)
			for (int j = c; j < n; j++)
				sum += g[x[i]][x[j]];

		ans[c] = sum;
   	}

   	for (int i = 0; i < n; i++)
   		cout << ans[i] << ' ';
	
	return 0;
}
