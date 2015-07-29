#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define PII pair <int, int>
#define MP make_pair
#define F first
#define S second

int d[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int u[8] = {2, 1, -1, -2, -2, -1,  1,  2};

int n, m;

bool check(int x, int y)
{
	if (x >= 0 && x < n)
		if (y >= 0 && y < m)
			return true;

	return false;
}

bool flag = false;

vector <vector <bool> > inst;

stack <pair <int, int> > st;

void dfs(int x, int y)
{
	inst[x][y] = true;

	st.push(MP(x, y));

	if ((int)st.size() == n * m)
		{
			while (!st.empty())	
				{
					cout << char((st.top().first) + 'a') << (st.top().second) + 1 << endl;
					st.pop();
				}
			exit(0);
		}


	for (int i = 0; i < 8; i++)
		{
			int tmpx = x + d[i];
			int tmpy = y + u[i];

			if (check(tmpx, tmpy) && !inst[tmpx][tmpy])
				{
					dfs(tmpx, tmpy);
				}
		}

	st.pop();

	inst[x][y] = false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	inst.assign(n, vector <bool> (m, false));

	dfs(0, 0);

	if (!flag)
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	
}