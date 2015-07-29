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
#define File "sixheroes"

int a[100001][4];

map <set <int>, bool> used;

bool can(int t, int b, int c)
{
	set <int> s;

	map <int, int> m;

	for (int i = 0; i < 3; i++)
		{
			m[a[t][i]]++;
			m[a[b][i]]++;
			m[a[c][i]]++;
		}

	if (m[t] == 2)
		{
			m.erase(t);
			s.insert(t);
		}
	else
		return false;

	if (m[c] == 2)
		{
			m.erase(b);
			s.insert(b);
		}
	else
		return false;


  	if (m[c] == 2)
  		{
  			m.erase(c);
  			s.insert(c);
  		}
	else
		return false;

	for (int i = 0; i < 3; i++)
		{
			if (m.begin() -> second != 1)
				return false;

			s.insert(m.begin() -> first);
			m.erase(m.begin());
		}


	//cout << s.size() << endl;	

	if (s.size() != 6)
		return false;

	if (used[s])	
		return false;

	used[s] = true;

	return true;
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
				{
					scanf("%d", &a[i][j]);
					a[i][j]--;
				}
		}

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			ans += can(i, a[i][0], a[i][1]);
			ans += can(i, a[i][0], a[i][2]);
			ans += can(i, a[i][1], a[i][2]);
		}


	cout << ans;	
	return 0;
}
