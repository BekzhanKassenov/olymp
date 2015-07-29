/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS

bool check(vector <int> &a)
{
	int n;

	for (int i = 0; i < 
}

int main()
{

	int n;

	cin >> n;

	vector <int> a(n);

	string s;

	cin >> s;
		
	for (int i = 0; i < n; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				a[i] = s[i] - '0';
			else
				a[i] = s[i] - 'a' + 10;
		}

	int ans = 0;

	for (int mask = 0; mask < (1 << n); mask++)
		{
			vector <int> tmp;
			for (int i = 0; i < n; i++)
				{
					if (mask & (1 << i))
						{
							tmp.push_back(a[i]);
						}
				}

			if (check(tmp))
				ans++;
		}

	return 0;
}
