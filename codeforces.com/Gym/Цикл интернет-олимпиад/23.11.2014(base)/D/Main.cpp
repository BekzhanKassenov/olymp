/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "lesson"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN], dp[MAXN];

int sign(int n) {
 	return (n > 0) - (n < 0);
}

bool equal(int a, int b) {
 	if (a == 0 || b == 0)	
 		return true;

 	return sign(a) == sign(b);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    	scanf("%d", &a[i]);
    
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
     	int diff = 0;

     	for (int j = i - 1; j >= 0; j--) {
     		dp[i] += dp[j];
     		dp[i] %= MOD;

     		int ndiff = a[j + 1] - a[j];

     		if (equal(diff, ndiff)) {
     		 	if (ndiff != 0)
     		 		diff = ndiff;
     		} else {
     		 	break;
     		}
     	}

     	//cerr << dp[i] << ' ';
    }

    printf("%d\n", dp[n]);

    return 0;
}
