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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

ll a[MAXN];
ll suffsum, suffans[MAXN];
ll sum, ans;
int n; 

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        sum += a[i];
    }

    if (sum % 3ll != 0) {
        puts("0");
        return 0;
    }

    sum /= 3ll;

    for (int i = n - 1; i >= 0; i--) {
        suffsum += a[i];

        if (suffsum == sum)
            suffans[i]++;

        suffans[i] += suffans[i + 1]; 
    }

    ll cursum = 0;

    for (int i = 0; i < n; i++) {
        cursum += a[i];

        if (cursum == sum)
            ans += suffans[i + 2];
    }

    printf("%I64d\n", ans);

    return 0;
}
