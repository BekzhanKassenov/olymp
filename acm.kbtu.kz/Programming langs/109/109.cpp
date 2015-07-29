#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > a;

vector <bool> used;

int n;

void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < n; i++)
		if (!used[i] && a[v][i])
			dfs(i);
}

int main()
{
	cin >> n;
	a.assign(n, vector <int>(n));
	used.assign(n,0);

	int cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
				cnt += a[i][j];
			}
	if (cnt / 2 != n - 1)
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
