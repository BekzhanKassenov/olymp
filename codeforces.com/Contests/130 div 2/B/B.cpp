/*********************************************
**       Solution by Bekjan Kasenov         **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) x * x
#define SZ size
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define INF 2000000000 
#define EPS 10E-9

vector <char> a, b;

bool dp[100][100][100][100];

bool check(int i, int j)
{
	if (a[i] == a[j] || b[i] == b[j])
		return true;

	return false;
}

bool dfs(int cnt, int one, int two, int three)
{
	if (cnt == 0)
		return true;

	if (dp[cnt][one][two][three])
		return 0;
	//cout << one << ' ' << two << ' ' << three << endl;

	if (cnt == 3)
		if (check(one, three) && (check(two, three)))
			return true;

	if (check(two, three) && dfs(cnt - 1, cnt - 3, one, three))
		return true;

	if (check(cnt - 3, three) && dfs(cnt - 1, three, one, two))
		return true;

	dp[cnt][one][two][three] = 1;
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	a.resize(n + 1);

	b.resize(n + 1);

	for (int i = 1; i <= n; i++)
		{
			char c;

			cin >> c;

			a[i] = c;

			cin >> c;
			
			b[i] = c;
		}

	if (n == 1 || dfs(n, n - 2, n - 1, n))
		cout << "YES";
	else
		cout << "NO";

	
	return 0;
}
