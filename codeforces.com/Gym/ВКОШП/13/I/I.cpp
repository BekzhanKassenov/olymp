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
#define File "python" 

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n, m;

	cin >> n >> m;

	int mx = (n + 1) / m;

	if ((n + 1) % m == 0)
		mx--;

	int mn = n / (m + 1);

	cout << mn << ' ' << mx;
}
