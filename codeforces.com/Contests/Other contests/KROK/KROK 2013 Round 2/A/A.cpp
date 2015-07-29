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

int gcd(int a, int b) {
	if (a == 0 || b == 0) 
		return a + b;

	return gcd(b % a, a);	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	set <int> s;

	int x;

	int g = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;
		g = gcd(x, g);
		s.insert(x);
	}

	for (int i = 1; i * i <= n; i++) {
		if (g % i == 0) {
			if (s.find(i) != s.end()) {
				cout << i;
				return 0;
			}

			if (s.find(g / i) != s.end()) {
				cout << g / i;
				return 0;
			}
		}
	}

	cout << -1;

	return 0;
}
