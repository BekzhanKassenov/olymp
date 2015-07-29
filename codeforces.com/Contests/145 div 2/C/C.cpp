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

	vector <int> a(n);

	vector <int> a1(n, 0), a2(n, 0);

	int cnt = 0;

	bool flag = false;

	cin >> a[0];

	if (a[0] > 0)
		{
			a1[0] = 1;
			flag = true;
		}

	if (a[0] == 0)
		cnt = 1;

	

	for (int i = 1; i < n; i++)
		{
			cin >> a[i];

			if (a[i] != 0)
				flag = true;
			if (a[i] > 0)
				{
					a1[i] = a1[i - 1] + 1;
					flag = true;
				}
			else
				a1[i] = a1[i - 1];
			
			if (a[i] == 0)
				cnt ++;

		}
	if (!flag)
		{
			cout << cnt << endl;
			return 0;
		}

	if (a[n - 1] < 0)
		a2[n - 1] = 1;

	for (int i = n - 2; i >= 0; i--)
		{                        
			if (a[i] < 0)
				{
					a2[i] = a2[i + 1] + 1;
				}    
			else
				a2[i] = a2[i + 1];
		}

	int ans = 20000000;

	for (int i = 0; i < n - 1; i++)
		{
			//cout << a[i] << ' ' << a1[i] << ' ' << a2[i + 1]  << endl;
			ans = min(ans, a1[i] + a2[i + 1] + cnt);
		}	

	cout << ans;
	return 0;
}

