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

int n, a[MAXN], cnt[MAXN];
int odd;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
     	scanf("%d", &a[i]);
     	cnt[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
    	odd += cnt[i] & 1;
   	} 

   	if (odd > 1) {
   	 	puts("0");
   	 	return 0;
   	}

   	int l = 1, r = n;
   	int in = 0, out = 0;

   	while (l < r && a[l] == a[r]) {
   	 	out++;
   	 	l++;
   	 	r--;
   	}

   	if (l >= r) {
   	 	printf("%I64d\n", 1ll * n * (n + 1) / 2);
   	 	return 0;
   	}

   	l = n / 2;
   	r = n - l + 1;

   	while (a[l] == a[r]) {
		in++;
		l--;
		r++;
    }

    int x = n / 2 - in - out;

    in *= 2;
    if (in > 0) {
     	in += n & 1;
    }

    long long ans = 1ll * out * out + 2ll * out * (x + in);
    printf("%I64d\n", ans);

    return 0;
}
