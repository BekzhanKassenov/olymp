/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "number"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

const long long LEFT  = 20689655172413ll;
const long long RIGHT = 79310344827586ll;

int k;

long long binpow(long long n, int st) {
 	long long res = 1;

 	while (st) {
 	 	if (st & 1) {
 	 	 	res *= n;
 	 	 	res %= MOD;
 	 	}

 	 	n *= n;
 	 	n %= MOD;
 	 	st >>= 1;
 	}

 	return res;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &k);

    long long a = binpow(10, 14);
    a = (a * (LEFT % MOD)) % MOD;
    a = (a + RIGHT) % MOD;

    long long ten_to_28 = binpow(10, 28);

    long long res = (binpow(ten_to_28, k) - 1 + MOD) % MOD;
	res = (res * binpow(ten_to_28 - 1, MOD - 2)) % MOD;
	res = (res * a) % MOD;

	printf("%I64d\n", res);

    return 0;
}
