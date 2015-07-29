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
#define INF 350
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

int n;

vector <int> a;

vector <vector <bool> > dp, calced;

bool dfs(int a, int b)
{
	if (a == 0 && b == 0)
		return false;

	if (a == 0 || b == 0)
		return true;

	if (calced[a][b])
		return dp[a][b];

	calced[a][b] = true;

	bool flag = false;

	for (int i = 1; i <= a; i++)
		flag = flag | (!dfs(a - i, b));

	for (int i = 1; i <= b; i++)
		flag = flag | (!dfs(a, b - i));

	int mn = min(a, b);

	for (int i = 1; i <= mn; i++)
		flag = flag | (!dfs(a - i, b - i));

	//cout << a << ' ' << b << ' ' << flag << endl;

	return (dp[a][b] = flag);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	    freopen("out", "w", stdout);
	#endif

	cin >> n;

	a.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (n == 1)
		{
			if (a[0] != 0)
				cout << "BitLGM";
			else
				cout << "BitAryo";

			return 0;	
		}	

   	if (n == 2)
   		{
   			dp.resize(400, vector <bool> (400, false));
   			
   			calced = dp;
   			
   			if (dfs(a[0], a[1]))
   				cout << "BitLGM";
   			else
   				cout << "BitAryo";

   			return 0;	
   		}

   	if (((a[0] ^ a[1]) ^ a[2]) != 0)
   		cout << "BitLGM";
   	else
   		cout << "BitAryo";	

	return 0;
}
