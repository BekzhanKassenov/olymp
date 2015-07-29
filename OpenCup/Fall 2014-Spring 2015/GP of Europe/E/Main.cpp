/****************************************
**          Solution by NU #2          **
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

int T, n, ansl, ansr;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
    	scanf("%d", &n);
    	ansl = ansr = -1;

    	for (int i = 2; i * i <= 2 * n; i++) {
    	 	if ((2 * n) % i == 0) {
    	 	 	int q = i;
    	 	 	int p = (2 * n) / i;

    	 	 	int r = (p + q - 1);
    	 	 	if (r % 2 != 0)
    	 	 		continue;

    	 	 	r /= 2;
    	 	 	int l = p - r;

    	 	 	if (r == l)
    	 	 		continue;

    	 	 	if (ansl == -1 || ansr - ansl > r - l) {
    	 	 	 	ansl = l;
    	 	 	 	ansr = r;
    	 	 	 	break;
    	 	 	}
    	 	}
    	}

    	if (ansl == -1) {
    	 	puts("IMPOSSIBLE");
    	} else {
    	 	printf("%d = ", n);

    	 	for (int i = ansl; i < ansr; i++) {
    	 	 	printf("%d + ", i);
    	 	}

    	 	printf("%d\n", ansr);
    	}
    }

    return 0;
}
