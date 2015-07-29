/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "repair"

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

int n, k;
long long a[MAXN];

bool check(long long h) {
 	long long diff = 0;

 	for (int i = 0; i < n; i++) {
 	 	if (h >= a[i])
 	 		diff += h - a[i];
 	}

 	return diff <= k;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n >> k;

    long long l = INF, r = INF;
    for (int i = 0; i < n; i++) {
     	cin >> a[i];
     	l = min(a[i], l);
    }

    long long ans = l;
    while (l <= r) {
		long long mid = (l + r) / 2;

		if (check(mid)) {
		 	ans = max(ans, mid);
		 	l = mid + 1;
		} else {
		 	r = mid - 1;
		}
    }

	cout << ans << endl;
    return 0;
}
