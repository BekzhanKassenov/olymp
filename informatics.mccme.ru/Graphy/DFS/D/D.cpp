#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;

vector <vector <int> > g;

vector <bool> used;

void dfs(int v)
{
	used[v] = 1;

	for (int i = 0; i < n; i++)
		if (!used[i] && g[v][i])
			dfs(i);
}

int main()
{
	cin >> n;

	int cnt = 0;

	g.resize(n, vector <int> (n));
	used.resize(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			{
				cin >> g[i][j];
				cnt += g[i][j];
			}

	if ((cnt >> 1) != n - 1)
		{
			cout << "NO";
			return 0;
		}

	cnt = 0;

	for (int i = 0; i < n; i++)
		if (!used[i])
			{
				dfs(i);
				cnt++;
			}

	if (cnt > 1)
		cout << "NO";
	else
		cout << "YES";

	return 0;	
}
