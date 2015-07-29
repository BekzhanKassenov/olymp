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

int gcd(int a, int b) {
	if (!a || !b)
		return a + b;

	return gcd(b, a % b);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b, p, q;

	cin >> a >> b >> p >> q;

	int g = gcd(a, b);
	a /= g;
	b /= g;

	g = gcd(p, q);
	p /= g;
	q /= g;

	int ansp = 1, ansq = 1;

	ansp = a * q - p * b;
	ansq = a * q;

	if (ansp < 0 ) {
		ansp = b * p - q  * a;
		ansq = b * p;
	}

	g = gcd(ansp, ansq);
	ansp /= g;
	ansq /= g;

	cout << ansp << '/' << ansq;

	return 0;
}
