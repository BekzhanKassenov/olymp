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

	multiset <int> s;

	int tmp;

	for (int i = 0; i < n; i++)
	   {
	   	cin >> tmp;
	   	s.insert(tmp);
	   }

	int ans = 0;

	while (ans < k)
		{
			tmp = *s.begin();
			s.erase(s.begin());

			tmp *= -1;
			s.insert(tmp);
			ans++;
		}

	ans = 0;

	for (set <int> :: iterator it = s.begin(); it != s.end(); it++)
		{
			//cout << *it << ' ';
			ans += *it;
		}

	cout << ans;	

	return 0;
}
