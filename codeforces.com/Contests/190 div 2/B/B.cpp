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

int solve(int a, int b, int c) {
	int ans = a / 3 + b / 3 + c / 3;

	a %= 3, b %= 3, c %= 3;

	while (a && b && c) {
		ans ++;
		a--, b--, c--;
	}

	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int r, g, b;

	cin >> r >> g >> b;

	if (r % 3 == g % 3 && g % 3 == b % 3) {
		cout << (r / 3 + g / 3 + b / 3 + r % 3);
		return 0;
	}

	int ans = solve(r, g, b);

	if (r && g && b) {
		for (int i = 1; i <= 3; i++) {
			int t_r = r - i;
			int t_g = g - i;
			int t_b = b - i;

			if (t_r >= 0 && t_g >= 0 && t_b >= 0)
				ans = max(ans, solve(t_r, t_g, t_b) + i);
		}
	}

	cout << ans;

	return 0;
}
