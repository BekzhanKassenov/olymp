/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

void right_turn(int& x, int& y)
{
	if (x == 1 && y == 0)
		{
			y = 1, x = 0;
			return;
		}

	if (y == 1 && x == 0)
		{
			x = -1, y = 0;
			return;
		}

	if (x == -1 && y == 0)
		{
			y = -1, x = 0;
			return;
		}	

	if (x == 0 && y == -1)
		y = 0, x = 1;	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int x, y;

	cin >> x >> y;

	if (x == 0 && y == 0)
		{
			cout << 0;
			return 0;
		}

	int cur_x = 1, cur_y = 0;

	vector <vector <bool > > used(400, vector <bool> (400));

	used[120][120] = true;

	int ans = 0;

	int dx = 1, dy = 0;

	while (cur_x != x || cur_y != y)
		{
			used[cur_x + 120][cur_y + 120] = 1;
			
			int tx = dx, ty = dy;
			
			right_turn(tx, ty);

			if (!used[cur_x + tx + 120][cur_y + ty + 120])
				{
					right_turn(dx, dy);
					ans++;
				}

			cur_x += dx;
			cur_y += dy;
			//cout << cur_x << ' ' << cur_y << endl;
		}

	cout << ans;	

	return 0;
}
