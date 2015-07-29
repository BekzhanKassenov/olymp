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
	double a, b, c;
	cin >> a >> b >> c;
	double a1 = (int)(sqrt((a * c) / b));
	double b1 = a / a1;
	double c1 = c / a1;
	cout << a1 << ' ' << b1 << ' ' << c1 << endl;
	printf("%.lf", (a1 + b1 + c1) * 4);
	return 0;
}
