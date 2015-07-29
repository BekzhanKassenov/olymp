#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

const int INF = (int) 2e9;

struct mat
{
	int mas[4][4];

	mat()	{}

	mat(int n)
		{
			for (int i = 3; i >= 0; i--)
				{
					for (int j = 3; j >= 0; j--)
						{
							mas[i][j] = n & 1;
							n >>= 1;
						}
				}
		}

	int get_num()
		{
			int ans = 0;

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					{
						ans <<= 1;

						ans += mas[i][j];
					}

			return ans;
		}

};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	mat a;

	char c;

	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				{
					c = getchar();
					if (c == 'W')
						a.mas[i][j] = 1;
					else
						a.mas[i][j] = 0;	
				}
			c = getchar();
		}

	int b[3][3];

	for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
		   	{
		   	 	c = getchar();
		   	 	b[i][j] = c - '0';
				}

			c = getchar();
		}

	#ifndef ONLINE_JUDGE

	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << a.mas[i][j];
			cout << endl;
		}
	
	cout << endl;

	for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << b[i][j];

			cout << endl;
		}

	#endif

	queue <int> q;

	vector <int> dist(1 << 16, INF);

	int n = a.get_num();

	dist[n] = 0;

	q.push(n);

	while (!q.empty())
		{
			int n = q.front();
			q.pop();

			mat tmp = mat(n);

			for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
						{
							mat r = tmp;

							int as = i - 1, bs = j - 1;

							for (int k = 0; k < 3; k++)
								{
									for (int t = 0; t < 3; t++)
										{
											if (b[k][t])
												if (as + k < 4 && bs + t < 4 && as + k >= 0 && bs + t >= 0)
													r.mas[as + k][bs + t] ^= 1;
										}
								}

							int z = r.get_num();

							if (dist[z] > dist[n] + 1)
								{
									dist[z] = dist[n] + 1;
									q.push(z);
								}

						}
				}

		}

	int ans = min(dist[0], dist[(1 << 16) - 1]);

	if (ans < INF)
		cout << ans;
	else
		cout << "Impossible";
}
