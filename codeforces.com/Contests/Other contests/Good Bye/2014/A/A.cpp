/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 30010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, t;
int a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
	
	scanf("%d%d", &n, &t);

	for (int i = 1; i < n; i++) {
	 	scanf("%d", &a[i]);
	}

	int cur = 1;
	while (cur < n) {
	 	cur += a[cur];

	 	if (cur == t) {
	 	 	puts("YES");
	 	 	return 0;
	 	}
	}

	puts("NO");
	
	return 0;
}
