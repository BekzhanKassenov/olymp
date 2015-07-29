#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int d, n, m;

char nmb[10][12][12];

vector <int> col[12][12];

int d[4] = {1, 0, 0, -1};
int u[4] = {0, 1, -1, 0};

bool ok(int x, int y)
{
	if (x >= 0 && x < n)
		if (y >= 0 && y < m)
			return true;

	return false;
}

string rec(int x, int y, int mask)
{
	if (mask == 0)
		return 0;

	inst[x][y] = 0;

	for (int i = 0; i < 4; i++)
		{
			int tmpx = x + d[i];
			int tmpy = y + u[i];

			if (ok(tmpx, tmpy))
				{
				}
		}
}

int main()
{
	freopen("image.in", "r", stdin);
	freopen("image.out", "w", stdout);

	cin >> d >> n >> m;

	for (int k = 0; k < d; k++)
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++)
				cin >> nmb[k][i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < d; k++)
				if (nmb[k][i][j] == 'B')
					col[i][j].push_back(k);

	
}
