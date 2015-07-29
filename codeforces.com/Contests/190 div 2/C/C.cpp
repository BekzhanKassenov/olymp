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
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> 
inline T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

string s;

int sign(int n) {
	if (n > 0)
		return 1;

	if (n == 0)
		return 0;

	return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b;

	scanf("%d%d", &a, &b);

	getline(cin, s);

	getline(cin, s);

	int x = 0, y = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		switch (s[i]) {
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
			case 'L':
				x--;
				break;
			case 'R':
				x++;
				break;
		}
	}

	int dx = x, dy = y;
	x = 0, y = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		if (a == x && b == y) {
			cout << "Yes";
			return 0;
		}
		if (dx == 0 && dy != 0) {
			if (a == x && (b - y) % dy == 0 && (sign(b - y) == sign(dy) || b == y)) {
				cout << "Yes";
				return 0;
			}
		}

		if (dy == 0 && dx != 0) {
			if (y == b && (a - x) % dx == 0 && (sign(a - x) == sign(dx) || a == x)) {
				cout << "Yes";
				return 0;
			}
		}

		if (dx != 0 && dy != 0) {
			if ((a - x) % dx == 0 && (b - y) % dy == 0 && (a - x) / dx == (b - y) / dy && (a - x) / dx >= 0) {
				cout << "Yes";
				return 0;
			}
		}
		switch (s[i]) {
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
			case 'L':
				x--;
				break;
			case 'R':
				x++;
				break;
		}

		if (a == x && b == y) {
			cout << "Yes";
			return 0;
		}

		if (dx == 0 && dy != 0) {
			if (a == x && (b - y) % dy == 0 && (sign(b - y) == sign(dy) || b == y)) {
				cout << "Yes";
				return 0;
			}
		}

		if (dy == 0 && dx != 0) {
			if (y == b && (a - x) % dx == 0 && (sign(a - x) == sign(dx) || a == x)) {
				cout << "Yes";
				return 0;
			}
		}

		if (dx != 0 && dy != 0) {
			if ((a - x) % dx == 0 && (b - y) % dy == 0 && (a - x) / dx == (b - y) / dy && (a - x) / dx >= 0) {
				cout << "Yes";
				return 0;
			}
		}

	}

	cout << "No";

	return 0;
}
