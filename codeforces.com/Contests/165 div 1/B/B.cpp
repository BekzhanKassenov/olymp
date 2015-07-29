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

const int maxn = 10000;

int n, m, Max[maxn], type[maxn];
double tmp;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d%lf", &type[i], &tmp);
		type[i]--;
	}

	int cur = 1;

	for (int i = 1; i < n; i++) {
		if (type[i] == type[i - 1])
			cur++;
		else {
			Max[type[i - 1]] = max(Max[type[i - 1]], cur);
			cur = 1;
		}
	}

	Max[type[n - 1]] = max(Max[type[n - 1]], cur);

	int res = 0;

	for (int i = 0; i < m; i++)
		res += Max[i];

	printf("%d", n - res);	

	return 0;
}
