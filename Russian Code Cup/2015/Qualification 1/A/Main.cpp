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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, l;
int a[MAXN], b[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d", &T);

    while (T--) {
    	scanf("%d%d", &n, &l);
    	for (int i = 0; i < n; i++) {
    		scanf("%d", &a[i]);
    	}

    	for (int i = 0; i < n; i++) {
    		scanf("%d", &b[i]);
    	}

    	sort(a, a + n);
    	sort(b, b + n);

    	int sum1 = 0, sum2 = 0;
    	for (int i = 0; i < l; i++) {
    		sum1 += a[i];
    	}

    	for (int i = n - l; i < n; i++) {
    		sum2 += b[i];
    	}

    	if (sum1 > sum2) {
    		puts("YES");
    	} else {
    		puts("NO");
    	}
    }
    return 0;
}
	