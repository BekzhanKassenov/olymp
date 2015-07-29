/***************************************
**    Solution by Bekzhan Kassenov    **
**    For: NU Opean Fall 2012         **
***************************************/
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
#define ll long long 
#define ull unsigned long long
#define File "regression"

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	cin >> n;

	double tmpx, tmpy, sumx = 0, sumy = 0;

	for (int i = 0; i < n; i++)
		{
			cin >> tmpx >> tmpy;
			sumx += tmpx;
			sumy += tmpy;
		}

	sumx /= n;

	sumy /= n;

	printf("0 %.6lf", sumx / sumy);

	return 0;
}
