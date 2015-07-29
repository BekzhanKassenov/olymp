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
#define PIS pair <int, string>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define LL long long
#define ULL unsigned long long

bool second(string &s)
{
	for (int i = 0; i < (int) s.length() - 1; i++)
		{
			if (s[i] == 'x' && s[i + 1] == 'y')
				{
					s.erase(s.begin() + i + 1);
					s.erase(s.begin() + i);
					return true;
				} 
		}

	return false;	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	cin >> s;

	int n = s.length();

	int cnt = 0;

	for (int i = 0; i < n; i++)
		{
			if (s[i] == 'x')
				cnt ++;
		}

	if (cnt > n - cnt)
		{
			for (int i = 0; i < cnt - n + cnt; i++)
				cout << 'x';
			return 0;	
		}
	else
		{
			for (int i = 0; i < n - cnt - cnt; i++)
				cout << 'y';
			return 0;
		}

	cout << endl;
	return 0;
}
