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
#define INF (int)1e9
#define MOD
#define EPS
#define File "bfs"

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;

	int s, f;

	cin >> s >> f;

	s--, f--;

	vector <vector <int> > g(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	vector <int> d(n, INF);

	d[s] = 0;

	vector <bool> used(n, false);
	
	used[s] = true;

	queue <int> q;

	q.push(s);

	while (!q.empty())
		{
			int v = q.front();

			q.pop();

			for (int i = 0; i < n; i++)
				{
					if (g[v][i] && !used[i])
						{
							q.push(i);
							used[i] = true;
							d[i] = d[v] + 1;
						}
				}
		}

	if (d[f] < INF)
		{
			cout << d[f];
		}
	else
		cout << 0;	

	return 0;
}
