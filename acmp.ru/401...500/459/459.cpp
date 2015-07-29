#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

int u[4] = {1, 0, -1, 0};
int d[4] = {0, 1, 0, -1};

int zn(char c)
{
	switch (c)
		{
			case 'N':
				return 0;
			case 'E':
				return 1;
			case 'S':
				return 2;
			case 'W':
				return 3;
		}
}

char obr(int n)
{
	switch (n)
		{
			case 0:
				return 'S';
			case 1:
				return 'W';
			case 2:
				return 'N';
			case 3:
				return 'E';
		}
}

int g[600][600], dst[600][600], used[600][600];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	string s;

	cin >> s;

	int cur_x = 280, cur_y = 280;

	g[cur_x][cur_y] = true;

	for (int i = 0; i < (int) s.length(); i++)
		{
			cur_x += u[zn(s[i])];
			cur_y += d[zn(s[i])];
			g[cur_x][cur_y] = 1;
		}

	queue <PII> q;

	q.push(MP(cur_x, cur_y));

	used[cur_x][cur_y] = true;

	while (!q.empty())
		{
			PII cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
				{
					PII tmp = cur;

					tmp.F += u[i];
					tmp.S += d[i];

					if (g[tmp.F][tmp.S] == 1 && !used[tmp.F][tmp.S])
						{
							dst[tmp.F][tmp.S] = dst[cur.F][cur.S] + 1;
							used[tmp.F][tmp.S] = true;
							q.push(tmp);
						}
				}
		}

	string ans;               

	PII cur = MP(280, 280);

	for (;;)
		{
			bool flag = false;
			
			for (int i = 0; i < 4; i++)
				{
					PII tmp = cur;

					tmp.F -= u[(i + 2) % 4];
					tmp.S -= d[(i + 2) % 4];

					if (dst[tmp.F][tmp.S] + 1 == dst[cur.F][cur.S] && used[tmp.F][tmp.S])
						{
						   ans += obr(i);

							flag = true;
							
							cur = tmp;
							
							break;
						}
				}
			if (!flag)
				break;
		}

	reverse(ans.begin(), ans.end());

	cout << ans;
	return 0;
}
