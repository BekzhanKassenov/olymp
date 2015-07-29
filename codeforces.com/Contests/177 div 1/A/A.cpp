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

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	int k;

	cin >> k;

	if (k > n) {
		cout << -1;
		return 0;
	}

	if (k == 1) {
	 	if (n == 1)
	 		cout << 'a';
	 	else
	 		cout << -1;

	 	return 0;	
	}

	for (int i = 0; i < n - k + 2; i++)
		cout << char('a' + i % 2);

	for (int i = 2; i < k; i++)
		cout << char('a' + i);


	return 0;
}
