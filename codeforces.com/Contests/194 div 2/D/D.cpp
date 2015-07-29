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
int n;

bool used_x[1010], used_y[1010];

bool can(pair <int, int> a) {
	if (a.F == 1 || a.F == n)
		return (!used_y[a.S]);

	return (!used_x[a.F]);	
}

int make(pair <int, int> a[4]) {
	int ans = 0;

	for (int i = 0; i < 4; i++)
		ans += can(a[i]);
	
  	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int m;

	cin >> n >> m;

	int x, y;

	int ans = 0;

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		used_x[x] = true;
		used_y[y] = true;
	}

	for (int i = 2; i <= n / 2; i++) {
		pair <int, int> a[4];
		a[0] = MP(i, 1);
		a[1] = MP(n - i + 1, n);
		a[2] = MP(n, i);
		a[3] = MP(1, n - i + 1); 

		int tmp = make(a);

		swap(a[0].F, a[1].F);
		swap(a[2].F, a[3].F);

		tmp = max(tmp, make(a));

		ans += tmp;
	}

	if (n % 2) {
		int k = (n + 1) / 2;

		if (can(MP(1, k)) || can(MP(n, k)) || can(MP(k, 1)) || can(MP(k, n)))
			ans++;
			
	}

	cout << ans << endl;

	return 0;
}
