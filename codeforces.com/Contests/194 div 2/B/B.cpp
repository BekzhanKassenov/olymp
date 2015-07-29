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

map <int, set <int> > X, Y;

PII a[8];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	for (int i = 0; i < 8; i++) {
		cin >> a[i].F >> a[i].S;
		X[a[i].F].insert(a[i].S);
		Y[a[i].S].insert(a[i].F);
	}

	if (X.size() != 3 || Y.size() != 3) {
		cout << "ugly";
		return 0;
	}

	map <int, set <int> > :: iterator it = X.begin();

	if ((it -> S).size() != 3) {
		cout << "ugly";
		return 0;
	}

	it++;
	if ((it -> S).size() != 2) {
		cout << "ugly";
		return 0;
	}
	it++;
	if ((it -> S).size() != 3) {
		cout << "ugly";
		return 0;
	}

	it = Y.begin();

	if ((it -> S).size() != 3) {
		cout << "ugly";
		return 0;
	}

	it++;
	if ((it -> S).size() != 2) {
		cout << "ugly";
		return 0;
	}
	it++;
	if ((it -> S).size() != 3) {
		cout << "ugly";
		return 0;
	}

	cout << "respectable";

	return 0;
}
