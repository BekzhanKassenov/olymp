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
#define VI vector <int>
#define LL long long
#define ULL unsigned long long

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;

	cin >> n;

	int ans = n / 2 + (n % 2);

	cout << ans << endl;

	vector <int> a(ans), b(n - ans);

	int cnt = 1;

	for (int i = 0; i < ans; i++)
		a[i] = cnt++;

	for (int i = 0; i < n - ans; i++)
		b[i] = cnt++;

	for (int i = 0; i < ans - (n % 2); i++)
		{
			cout << ans << ' ';

			for (int j = 0; j < ans; j++)
				cout << a[j] << ' ';

			cout << endl;

			if (i != ans - (n % 2) - 1)
				swap(a[i], b[i]);
		}

	if (n % 2)
		{
			cout << ans - 1 << ' ';
			for (int i = 0; i < ans - 1; i++)
				cout << a[i] << ' ';
		}

	return 0;
}

