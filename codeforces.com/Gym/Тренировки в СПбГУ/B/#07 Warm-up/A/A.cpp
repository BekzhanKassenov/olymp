#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define MP make_pair
#define F first
#define S second

int d[4] = {1, 0, 0, -1};
int u[4] = {0, 1, -1, 0};

int n, m;

bool ok(int x, int y)
{
	if (x >= 0 && x < n)
		if (y >= 0 && y < m)
			return true;

	return false;
}

int main()
{
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);

	cin >> n >> m;

	vector <string> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int x = -1, y = -1;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{
					if (a[i][j] == 'A')
						x = i, y = j;
				}
		}

	char c = 'B';

	int cnt = 0;

	while (true)
		{
			bool flag = false;

			if (c == 'Z' + 1)	
				{
					cout << "YES";
					return 0;
				}

			for (int i = 0; i < 4; i++)
				{
					int cur_x = x + u[i];
					int cur_y = y + d[i];

					if (ok(cur_x, cur_y))
						{
							if (a[cur_x][cur_y] == c)
								{
									x = cur_x;
									y = cur_y;
									c++;
								}
						}
				}

			cnt++;

			if (cnt > 30)
				{
					cout << "NO";
					return 0;
				}
		}
		
	return 0;
}
