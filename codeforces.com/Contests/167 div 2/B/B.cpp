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

int f(int n)
{
	if (n == 0)
		return 0;

	if (n & 1)
		return f(n >> 1) + 1;
	else
		return f(n >> 1);	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int cnt[100] = {0};

	for (int i = 0; i < n; i++)
		cnt[f(a[i])] ++;

	long long ans = 0;

	for (int i = 0; i < 100; i++)
		{
			ans += (cnt[i] * 1ll * (cnt[i] - 1)) >> 1;
		}

	cout << ans << endl;	

	return 0;
}
