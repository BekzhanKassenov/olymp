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

long long val[5], cost[5];

int main()
{
	long long n;
	cin >> n;
	vector <long long> a;
	a.resize(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < 5; i++)
		{
			cin >> cost[i];
			val[i] = 0;
		}
	
	long long k = 0;

	for (int i = 0; i < n; i++)
		{
			k += a[i];
			for (int j = 4; j >= 0; j--)
				{
					long long m = k / cost[j];
					k %= cost[j];
					val[j]+=m;
				}
		}
	for (int i = 0; i < 5; i++)
		cout << val[i] << ' ';
	
	cout << endl << k;
	return 0;
}
