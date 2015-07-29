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
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	int n;
	cin >> n;

	LL z = 1000000;

	vector <int> prime(z + 1, 1);

	prime[0] = prime[1] = false;
	for (LL i = 2; i <= z; ++i)
		if (prime[i])
			if (i * i <= z)
				for (LL j = i * i; j <= z; j += i)
					prime[j] = false;

	double x;

	for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x == 1)
				{
					cout << "NO" << endl;
					continue;
				}
			double k = sqrt(x);
			LL a = (long long) k;
			if (a * a == x)
				{
					if (prime[a])
						cout << "YES" << endl;
					else
						cout << "NO" << endl;
				}
			else
				cout << "NO" << endl;
		}

	return 0;
}
