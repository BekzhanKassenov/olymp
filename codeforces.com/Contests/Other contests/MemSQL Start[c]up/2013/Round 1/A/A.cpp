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

vector <pair <PII, PII> > a;
pair <PII, PII> tmp;

int n;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	scanf("%d", &n);
	a.resize(n);

	long long S = 0;
	int minx = 32000, maxx = -32000, miny = 32000, maxy = -32000;

	for (int i = 0; i < n; i++) {                
		scanf("%d%d%d%d", &a[i].F.F, &a[i].F.S, &a[i].S.F, &a[i].S.S);
		S += abs(a[i].S.F - a[i].F.F) * 1ll * abs(a[i].S.S - a[i].F.S);
		minx = min(minx, a[i].F.F);
		maxx = max(maxx, a[i].S.F);
		miny = min(miny, a[i].F.S);
		maxy = max(maxy, a[i].S.S);
	}

	if (S == (maxx - minx) * 1ll * (maxy - miny) && maxx - minx == maxy - miny) {
		for (int i = 0; i < n; i++) {
			if (a[i].F.F < minx || a[i].F.F > maxx || a[i].S.F < minx || a[i].S.F > maxx) {
				cout << "NO";
				return 0;
			}

			if (a[i].S.S < miny || a[i].S.S > maxy || a[i].F.S < miny || a[i].F.S > maxy) {
				cout << "NO";
				return 0;
			}
		}
		cout << "YES";
	}
	else
		cout << "NO";

	return 0;
}
