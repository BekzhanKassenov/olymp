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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int t;
long long n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &t);

    while (t--) {
    	scanf("%lld", &n);

    	long long sum = (n * (n + 1)) / 2;
    	for (int i = 0; (1 << i) <= n; i++) {
    		sum -= (1ll << (i + 1));
    	}

    	printf("%lld\n", sum);
    }

    return 0;
}
