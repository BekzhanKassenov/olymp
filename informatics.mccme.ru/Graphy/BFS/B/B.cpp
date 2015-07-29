#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int a[25][25];
pair <int, int> p[25][25];

bool used[25][25];

int n;

bool check(int x, int y)
{
	if (x > 0 && x <= n)
		if (y > 0 && y <= n)
			if (!used[x][y])
				return true;
	return false;
}

void go(int x, int y, pair <int, int> pr)
{
	used[x][y] = true;
	a[x][y] = a[pr.first][pr.second] + 1;
	p[x][y] = pr;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x, y, x1, y1;
	cin >> n >> x >> y >> x1 >> y1;
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			{
				a[i][j] = 1000;
				p[i][j] = make_pair(-1, -1);
		   }

	a[x][y] = 0;
	used[x][y] = true;
	queue < pair <int, int> > q;
	q.push(make_pair(x,y));
	while (!q.empty())
		{
			pair <int, int> pr = q.front();
			q.pop();
			x = pr.first;
			y = pr.second;
			if (check(x - 2, y + 1))
				{
					q.push(make_pair(x - 2, y + 1));
					go(x - 2, y + 1, pr);
				}
			if (check(x - 1, y + 2))
				{
					q.push(make_pair(x - 1, y + 2));
					go(x - 1, y + 2, pr);
				}
			if (check(x + 1, y + 2))
				{
					q.push(make_pair(x + 1, y + 2));
					go(x + 1, y + 2, pr);
				}
			if (check(x + 2, y + 1))
				{
					q.push(make_pair(x + 2, y + 1));
				   go(x + 2, y + 1, pr);
				}
			if (check(x + 2, y - 1))
				{
					q.push(make_pair(x + 2, y - 1));
					go(x + 2, y - 1, pr);
				}
		   if (check(x + 1, y - 2))
				{
					q.push(make_pair(x + 1, y - 2));
					go(x + 1, y - 2, pr);
				}
		   if (check(x - 1, y - 2)) 
				{        
					q.push(make_pair(x - 1, y - 2));
					go(x - 1, y - 2, pr);
				}
		   if (check(x - 2, y - 1))
				{
					q.push(make_pair(x - 2, y - 1));
					go(x - 2, y - 1, pr);
				}
		}
  	cout << a[x1][y1];
  	vector <pair <int, int> > ans;
  	for (pair <int, int> i = make_pair(x1, y1); i != make_pair(-1, -1); i = p[i.first][i.second])
  		ans.push_back(i);
  	reverse(ans.begin(), ans.end());	
  	cout << endl;
  	for (int i = 0; i < ans.size(); i++)
  		cout << ans[i].first << ' ' << ans[i].second << endl; 
  	return 0;
}
