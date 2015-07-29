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

int get(int a)
{
	int maxx = 0;

	for (int i = 0; i < 21; i++)
		if (a & (1 << i))
			maxx = i;

	int ans = (1 << (maxx + 1)) - 1;

	return (ans ^ a);	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> a(n + 1);
	
	for (int i = n; i >= 0; i--) {
		if (a[i] == 0) {
			for (int j = 21; j >= 0; j--) {
			int tmp = get(i);

			if ((i ^ tmp) == i + tmp && a[tmp] == 0)
				{
					a[tmp] = i;
					a[i] = tmp;
					break;
				}
			}	
		}
	}

	ll ans = 0;

	for (int i = 0; i <= n; i++)
		ans += (a[i] ^ i);

	cout << ans << endl;

	for (int i = 0; i <= n; i++)
		cout << a[i] << ' ';

	return 0;
}
