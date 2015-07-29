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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	
	cin >> n;

	vector <int> a(n);

	vector <int> sum(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sum[0] = a[0];

	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i];

	int ans = a[0];

	cout << "+";

	string s;

	int pos = 1;

	while (true)
		{
			ans += a[pos];

			cout << "+";

			if (ans >= sum[n - 1] - sum[pos])
				break;

			pos++;

		}

	for (int i = pos + 1; i < n; i++)
		cout << '-';	

	return 0;
}
