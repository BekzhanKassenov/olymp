/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "numbers"

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

int a, b, c, d;

int power(int a, int n) {
 	int res = 1;

 	for (int i = 0; i < n; i++)
 		res *= a;

 	return res;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d%d%d", &a, &b, &c, &d);

    int cnt = 0, ans = -1;
    for (int x = 1; x <= 3; x++) {
     	if (power(a, x) + power(b, x) + power(c, x) == d) {
			cnt++;
			ans = x;
     	}
    }

    if (cnt > 1)
    	ans = -1;

    printf("%d\n", ans);	

    return 0;
}
