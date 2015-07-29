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

int u[4] = {1, 0, 0, -1};
int d[4] = {0, 1, -1, 0};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <int> a(n);

	vector <vector <int> > dist(n);

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			dist[i].resize(a[i] + 1, -1);
		}

	queue <PII> q;

	PII s, f;

	cin >> s.F >> s.S >> f.F >> f.S;

	s.F--, s.S--, f.F--, f.S--;

	dist[s.F][s.S] = 0;

	q.push(s);

	while (!q.empty())
		{
			PII now = q.front();
			q.pop();

			if (now == f)
				break;

			for (int i = 0; i < 4; i++)
				{
					PII tmp = now;

					tmp.F += u[i];
					tmp.S += d[i];

					if (tmp.F < n && tmp.F >= 0)
						{
							if (tmp.S >= 0)
								{
									if (tmp.S > a[tmp.F])
										tmp.S = a[tmp.F];
									if (dist[tmp.F][tmp.S] == -1)
										{
											dist[tmp.F][tmp.S] = dist[now.F][now.S] + 1;
											q.push(tmp);
										}
								}
						}
				}
		}

	cout << dist[f.F][f.S];
	return 0;
}
