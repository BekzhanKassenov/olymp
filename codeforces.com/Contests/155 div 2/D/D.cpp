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

int n, m;

int u[4] = {1, 0, 0, -1};
int dow[4] = {0, 1, -1, 0};

vector <PII> d_bfs(PII t, int ds, vector <vector <int> > &d)
{
	d.assign(n, vector <int> (m, -1));
	
	d[t.F][t.S] = 0;

	queue <PII> q;

	vector <PII> ans;

	q.push(t);

	ans.PB(t);

	while (!q.empty())
		{
			PII now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
				{
					PII tt;
					tt.F = now.F + u[i];
					tt.S = now.S + dow[i];

					if (g[tt.F][tt.S] != -1 && d[tt.F][tt.S] == -1)
						{	
							d[tt.F][tt.S] = d[now.F][now.S] + 1;
							if (d[tt.F][tt.S] < ds)
								q.push(tt);

							if (g[tt.F][tt.S] == 1)
								ans.push_back(tt);
						}
				}
		}

	if (g[t.F][t.S] == 1)
		ans.push_back(t);

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int d;
	
	cin >> n >> m >> d;

	g.assign(n, vector <int> (m));

	char c;

	getchar();

	vector <PII> rats;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{	
					c = getchar();
					if (c == 0)
						g[i][j] = 0;
					if (c == 'R')
						{
							g[i][j] = 1;

							rats.PB(MP(i, j));
						}

					if (c == 'X')
						g[i][j] = -1;
				}
			getchar();
		}

	if (rats.empty() || (int)rats.size() > 4 * d * d + 1)
		{
			cout << -1;
			return 0;
		}

	vector <vector <int> > dst;

	vector <PII> fs = d_bfs(rats[0], d, dst);

	for (int ch = 0; ch < (int)fs.size(); ch++)
		{
			vector <PII> tmp = d_bfs(fs[ch], d, dst);
			
			vector <vector <int> > dst2;

			set <PII> s(tmp.begin(), tmp.end());

			int pos = -1;

			for (int i = 1; i < (int)rats.size(); i++)
				{
					if (s.find(rats[i]) == s.end())
						{	
							pos = i;
							break;						
						}
				
				}

			tmp = d_bfs(rats[pos], d, dst2);

			for (int j = 0; j < (int) tmp.size(); j++)
				{
					vector <PII> z = d_bfs(tmp[j], d, dst2);

					bool flag = true;

					for (int p = 0; p < (int) rats.size(); p++)
						{
							if (dst[rats[p].F][rats[p].S] == -1 && dst2[rats[p].F][rats[p].S] == -1)
								{
									flag = false;
									break;
								}
						}

					if (flag)
						{
							cout << fs[ch].F + 1 << ' ' << fs[ch].S + 1 << ' ' << tmp[j].F + 1 << ' ' << tmp[j].S + 1 << endl;
							return 0;
						}
				}

		}

	cout << -1;

	return 0;
}
