/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "sequence"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 4 * 10000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN], b[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
     	scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
     	b[i + 2] = a[i];
     	a[i + 1] -= b[i + 2];
     	a[i + 2] -= b[i + 2];
    }

    for (int i = 0; i < n + 2; i++)
    	printf("%d ", b[i]);

    puts("");

    return 0;
}
