#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int u[4] = {1, 0, -1,  0};
int d[4] = {0, 1,  0, -1};

int g[500][500];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int pos = 0;

	int cur_x = 250, cur_y = 250;

	string s;
	
	cin >> s;

	g[cur_x][cur_y] = true;

	int cnt = 0;

	for (int i = 0; i < (int) s.length(); i++)
		{
			if (s[i] == 'S')
				{
					cur_x += u[pos];
					cur_y += d[pos];

					cnt++;

					if (g[cur_x][cur_y] == 1)
						{
							cout << cnt;
							return 0;
						}

					g[cur_x][cur_y] = 1;
				}

			if (s[i] == 'L')
				{
					pos ++;

					pos %= 4;
				}

			if (s[i] == 'R')
				{
					pos--;

					pos = (pos + 4) % 4;
				}
		}
	cout << -1;
	return 0;
}
