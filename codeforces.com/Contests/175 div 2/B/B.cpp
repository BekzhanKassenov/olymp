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

	int n, s, t;

	cin >> n >> s >> t;

	vector <int> a(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vector <int> dist(n + 1, INF);

	dist[s] = 0;

	int k = s;

	for (;;)
		{
			if (dist[a[k]] < INF)
				break;

			dist[a[k]] = dist[k] + 1;

			k = a[k];
		}

	if (dist[t] == INF)
		cout << -1;
	else
		cout << dist[t];	

	return 0;
}
