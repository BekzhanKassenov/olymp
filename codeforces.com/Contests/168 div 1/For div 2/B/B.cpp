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

char a[100][100];

bool can(int x, int y, int _x, int _y) {
	bool ans = true;

	if (x == _x) {
		for (int i = min(y, _y); i <= max(y, _y) && ans; i++)
			ans = (a[x][i] == 'B');

	   	return ans;
	}

	for (int i = min(x, _x); i <= max(x, _x) && ans; i++) 
		ans = (a[i][y] == 'B');

	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		getchar();

		for (int j = 0; j < m; j++)
			a[i][j] = getchar();
	}

	bool ans = true;

	for (int i = 0; i < n && ans; i++) {
		for (int j = 0; j < m && ans; j++) {
			if (a[i][j] == 'B') {
				for (int ii = 0; ii < n && ans; ii++) {
					for (int jj = 0; jj < m && ans; jj++) {
				 		if (a[ii][jj] == 'B' && !(can(i, j, ii, jj) || (can(i, j, ii, j) && can(ii, j, ii, jj)) || (can(i, j, i, jj) && can(i, jj, ii, jj))))
				 			ans = false; 
					}
				}
		   	}
		}
	}

	puts(ans ? "YES" : "NO");

	return 0;
}
