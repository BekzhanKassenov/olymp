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

bool can(int a, int b, int& c) {
	int cnt = 0;

	while (!(a & 1)) {
		a >>= 1;
		cnt += a;
	}

	c = a;

	cnt += (a * (a - 1)) >> 1;

	return (cnt == b);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);

	#endif

	int n, tmp;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		bool flag = false;
		
		for (int j = 1; j <= 10000; j++) {
			if (can(j, i, tmp)) {
				if (!flag) {
					cout << i << " : " << endl;
					flag = true;
				}
			   	cout << j << ' ' << tmp << endl;
			}
		}
		if (flag)
			cout << endl;
	}
	return 0;

	return 0;
}
