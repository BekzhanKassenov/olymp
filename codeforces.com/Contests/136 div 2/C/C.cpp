/*********************************************
**       Solution by Bekjan Kasenov         **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 1000000000
#define EPS 10E-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define VI vector <int>

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int n;
	cin >> n;
	VI a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	VI b = a;
	sort(b.begin(), b.end());

	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (b[i] != a[i])
			cnt++;

	if (cnt == 2 || cnt == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
