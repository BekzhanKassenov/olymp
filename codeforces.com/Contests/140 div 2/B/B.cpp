/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>


using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 2000000000
#define EPS 10e-14
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

	vector <long long> a(n + 2);

	for (int i = 1; i <= n; i++)
		cin >> a[i];

  	vector <long long> b(n + 2);

  	for (int i = 1; i <= n; i++)
  		b[a[i]] = i;

  	int m;
  	cin >> m;

  	long long a1 = 0, a2 = 0;

  	for (int i = 0; i < m; i++)
  		{
  			int k;
  			cin >> k;

  			a1 += b[k];

  			a2 += n - b[k] + 1;
  		}

  	cout << a1 << ' ' << a2 << endl;


	return 0;
}
