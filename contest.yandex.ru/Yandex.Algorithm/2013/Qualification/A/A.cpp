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

int n, l, cnt[2], t, d;

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d", &n, &l);

	for (int i = 0; i < n; i++) {
	 	scanf("%d%d", &t, &d);

	 	if (d == -1) {
	 	 	cnt[t - 1]++;	
	 	} else {
	 		if (d <= l)
	 			cnt[t - 1] += 2;
	 		else
	 			cnt[t - 1] += 3;	
	 	}
	}

	printf("%d:%d", cnt[0], cnt[1]);

	return 0;
}
