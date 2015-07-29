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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s1 = "WBWBWBWB";

	string s2 = "BWBWBWBW";

	string s;

	for (int i = 0; i < 8; i++)
		{
			cin >> s;

			if (s != s1 && s != s2)
				{
					cout << "NO";
					return 0;
				}


		}
	cout << "YES";
	return 0;	
	return 0;
}
