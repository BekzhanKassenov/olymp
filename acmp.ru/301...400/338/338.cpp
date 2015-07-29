#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

int u[4] = {1, 0, 0, -1};
int d[4] = {0, 1, -1, 0};

int n, m;

void bfs(PII f, vector <vector <int> > &dst)
{
	queue <PII> q;

	q.push(f);

	dst[f.F][f.S] = 1;

	while (!q.empty())
		{
			f = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
				{
					PII tmp = f;
					tmp.F += u[i];
					tmp.S += d[i];

					if (tmp.F < n && tmp.F >= 0)
						if (tmp.S >= 0 && tmp.S < m)
							if (dst[tmp.F][tmp.S] == 0)
								{
									q.push(tmp);
									dst[tmp.F][tmp.S] = 1;
								}
				}
		}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;

	vector <vector <int> > d(n, vector <int> (m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> d[i][j];

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!d[i][j])
				{
					bfs(MP(i, j), d);
					ans++;
			  	}

  	cout << ans;
  	
  	return 0;
}
