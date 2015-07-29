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

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	string s;

	cin >> s;

	int cnt[3] = {0};

	for (int i = 0; i < n; i++)
		{
			if (s[i] == 'A')
				cnt[0]++;

			if (s[i] == 'I')
				cnt[1]++;

			if (s[i] == 'F')
				cnt[2]++;	
		}

	if (cnt[1] == 0)
		cout << cnt[0];
	else
		if (cnt[1] == 1)
			cout << 1;
		else
			cout << 0;	

	return 0;
}
