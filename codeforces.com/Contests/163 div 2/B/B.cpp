/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, k;

	cin >> n >> k;

	string s;

	cin >> s;

	for (int j = 0; j < k; j++)
	 	{
	 	   bool flag = true;

	 	   string tmp = s;

	 	   for (int i = 1; i < n; i++)
	 	   	{
	 	   		if (s[i] == 'G' && s[i - 1] == 'B')
	 	   			swap(tmp[i], tmp[i - 1]);
	 	   	}

	 	   s = tmp;
	 	}

	cout << s << endl;
	return 0;
}
