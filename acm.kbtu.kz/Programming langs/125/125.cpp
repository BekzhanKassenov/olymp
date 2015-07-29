#include <iostream>
#include <vector>

using namespace std;

vector <int> col;

vector <vector <int> > a;

bool flag = true;

int n;

void dfs(int v, int color, int pr = -1)
{
	col[v] = color;
	color = 3 - color;
	for (int i = 0; i < n; i++)
		{	
			if (col[i] == -1 && a[v][i])
				{
					dfs(i, color, v);
				}
			if (a[v][i] && col[i] == col[v] && i != pr)
				{
					flag = false;
				}
		}
}

int main()
{
	cin >> n;
	a.assign(n, vector <int>(n));
	col.assign(n, -1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		if (col[i] == -1)
			dfs(i, 1);

	if (flag)
		{
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
				cout << col[i] << ' ';
			return 0;
		}
	else
		cout << "NO";
	return 0;
}
