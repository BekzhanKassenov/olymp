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
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define MOD (1000 * 1000 * 1000 + 7)

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> 
T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
T sqr(T n) {
	return (n * n);
}

template <typename T>
T max(T a, T b) {
	return (a > b ? a : b);
}

template <typename T>
T min(T a, T b) {
	return (a < b ? a : b);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, x, y, tx, ty;

	cin >> n >> x >> y >> tx >> ty;

	string s;

	getline(cin , s);

	getline(cin , s);

	for (int i = 0; i < n; i++) {
		int t_x = x, t_y = y;

		switch (s[i]) {
			case 'S':
				t_y--;
				break;
			case 'E':
				t_x++;
				break;
			case 'N':
				t_y++;
				break;
			case 'W':
				t_x--;
				break;
		}

		if (abs(tx - t_x) + abs(ty - t_y) < abs(tx - x) + abs(ty - y))
			x = t_x, y = t_y;

		if (x == tx && y == ty) {
			cout << i + 1;
			return 0;
		}
	}

	cout << -1;

	return 0;
}
