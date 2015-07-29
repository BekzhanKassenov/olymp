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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, mul = 1;
int a[MAXN], ans[MAXN];

bool prime(int n) {
 	for (int i = 2; i * i <= n; i++)
 		if (n % i == 0)
 			return false;

	return true;
}

bool square(int n) {
 	int k = sqrt(n);
 	return k * k == n;
}

int binpow(int a, int st) {
	int res = 1;

	while (st) {
		if (st & 1) {
		 	res = (1ll * res * a) % n;
		}

		a = (1ll * a * a) % n;
		st >>= 1;
	}

	return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    if (n == 1) {
    	puts("YES");
    	puts("1");
    	return 0;
    } else if (prime(n)) {
        ans[n] = n;
        ans[1] = 1;

        for (int i = 2; i < n; i++) {
         	int revmul = binpow(mul, n - 2);
         	ans[i] = (1ll * i * revmul) % n;
         	mul = (1ll * ans[i] * mul) % n;
        }
    } else if (square(n) && prime(sqrt(n))) {
     	for (int i = 1; i <= n; i++)
     		a[i] = i;

     	for (int i = sqrt(n); i < n - 1; i++) {
     	 	swap(a[i], a[i + 1]);
     	}

     	ans[1] = 1;
     	ans[n] = n;

     	for (int i = 2; i < n; i++) {
         	int revmul = binpow(mul, n - 3);
         	ans[i] = (1ll * a[i] * revmul) % n;
         	mul = (1ll * ans[i] * mul) % n;
        }

    } else {
     	puts("NO");
     	return 0;
    }

    puts("YES");

    for (int i = 1; i <= n; i++)
    	printf("%d\n", ans[i]);
    
    return 0;
}
