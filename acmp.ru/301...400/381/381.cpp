#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

#define INF 10000
#define F first
#define S second

int u[4] = {1, -1, 0,  0};
int d[4] = {0,  0, 1, -1};

int n;

vector <vector <int> > a;

bool check(int x, int y)
{
	if (x >= 0 && x < n)
		if (y >= 0 && y < n)
			if (a[x][y] == INF || a[x][y] != -1)
				return true;
   return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin >> n;
	
	a.assign(n, vector <int> (n, INF));
	
	int x = 0, y = 0, x1 = 0, y1 = 0;
	
	char c;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			{
				cin >> c;
				if (c == 'O')
					a[i][j] = -1;
				if (c == 'X')
					{
						x1 = i;
						y1 = j;
					}
				if (c == '@')
					{
						x = i;
						y = j;
						a[x][y] = 0;
					}
			}
	queue <pair <int, int> > q;
	
	q.push(make_pair(x,y));
	
	while (!q.empty())
		{
			pair <int, int> k = q.front();
			
			q.pop();
			
			for (int i = 0; i < 4; i++)
				if (check(k.F + u[i], k.S + d[i]) && a[k.F + u[i]][k.S + d[i]] > a[k.F][k.S] + 1)
					{
						a[k.F + u[i]][k.S + d[i]] = a[k.F][k.S] + 1;
						q.push(make_pair(k.F + u[i], k.S + d[i]));
					}
		}
	if (a[x1][y1] == INF)
		{
			cout << "No";
			return 0;
		}
	vector <vector <bool> > us(n, vector <bool> (n,0));
	us[x1][y1] = true;
	while (!(x1 == x && y1 == y))
		{
			for (int i = 0; i < 4; i++)
				if (check(x1 + u[i], y1 + d[i]) && a[x1 + u[i]][y1 + d[i]] == a[x1][y1] - 1)
					{
						x1 += u[i];
						y1 += d[i];
						us[x1][y1] = true;
						break;
					}
		}
	cout << "Yes" << endl;
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				{
					if (!us[i][j])
						{
							if (a[i][j] == -1)
								cout << 'O';
							else
								cout << '.';
						}
					else
						{
							if (i == x && j == y)
								cout << '@';
							else
								cout << '+';
						}
				}
			cout << endl;
	  }
  return 0;

}
