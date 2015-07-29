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

int cnt(int n)
{
	int ans = 0;

	while (n)
		{
			if (n % 10 == 4 || n % 10 == 7)
				ans++;
			n /= 10;
		}

	return ans;	
			
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, k;

	cin >> n >> k;

	int ans = 0;

	int x;

	for (int i = 0; i < n ;i++)
		{
			cin >> x;

			if (cnt(x) <= k)
				ans++;
		}

	cout << ans;	

	return 0;
}
