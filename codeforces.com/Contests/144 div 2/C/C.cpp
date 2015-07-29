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
#define ULL unsigned long long

int g[101][101];

const int N = 100;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	int k;

	cin >> k;

	int cnt = 0;

	for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < i; j++)
				{
					int tmp = 0;

					for (int q = 0; q < N; q++)
						{
							if (i != q && j != q && g[i][q] && g[j][q])
								tmp++;
						}	

					if (cnt + tmp <= k)
						{
							cnt += tmp;
							g[i][j] = g[j][i] = 1;
						}

					if (cnt == k)
						break;
						
				}
		}

	cout << N << endl;

	for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				{
					cout << g[i][j];
				}
			cout << endl;
		}

	return 0;
}
