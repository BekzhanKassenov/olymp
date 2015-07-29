/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "suffixgame"

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

int n, a[MAXN];
int diff;
int cnt[2];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
     	scanf("%d", &a[i]);
     	diff = a[i] - a[i - 1];
     	cnt[diff & 1]++;
    }

    if (cnt[0] % 2 == 0) {
		puts("Second");
    } else {
		puts("First");
    }

    return 0;
}
