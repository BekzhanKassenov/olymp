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
#define EPS 1e-1
#define File "jediacademy" 

vector <int> kr;

vector <vector <int> > pr;

vector <int> cnt;

vector <bool> used;

int n;

int a, b;

int q[1000000];

void init()
{
	kr.resize(n);
	pr.resize(n);
	cnt.resize(n);
	used.resize(n);
}

int check(int pos)
{
	used.assign(n, false);

	vector <int> c = cnt;

	int ans = 0;

	queue <int> q[2];

	for (int i = 0; i < n; i++)
		{
			if (c[i] == 0 && !used[i])
				{
					used[i] = true;
					q[kr[i] - 1].push(i);
				}
		}

	for (;;)
		{
			if (q[pos - 1].empty())
				break;

			ans += a;
			while (!q[pos - 1].empty())
				{
					int now = q[pos - 1].front();
					q[pos - 1].pop();
					for (size_t i = 0; i < pr[now].size(); i++)
						{
							int to = pr[now][i];
							c[to] --;
							if (c[to] == 0 && !used[to])
								{
									used[to] = true;
									q[kr[to] - 1].push(to);
								}
						}
					ans += b;
				}
			pos = 3 - pos;
		}

	if (ans == 0)
		return INF;

	return ans;
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	scanf("%d", &n);

	init();

	for (int i = 0; i < n; i++)
		{
			scanf("%d", &kr[i]);

			scanf("%d", &cnt[i]);

			int x;

			for (int j = 0; j < cnt[i]; j++)
				{
					scanf("%d", &x);
					x--;

					pr[x].push_back(i);
				}
		}

	scanf("%d%d", &a, &b);

	int ans = min(check(1), check(2));

	printf("%d", ans);

	return 0;
}
