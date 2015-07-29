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
#define EPS 1e-1
#define File "loudcats" 

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n, m, a;

	cin >> n >> m >> a;

	int cnt = n * m;

	vector <int> v(cnt);
	
	for (int i = 0; i < cnt; i++)
		cin >> v[i];

	int ans = 0;

	for (int i = cnt - m - 1; i >= 0; i --)
		{
			if (v[i + m] > 2 * v[i])
				ans += a;
		}

	cout << ans;
	return 0;

	return 0;
}
