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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

ll n, k, d1, d2;
ll sum, w1, w2, w3;
int T, temp;

bool check(ll a, ll b) {
    w2 = abs(k - a - b);

    if (n % 3 != 0 || w2 % 3 != 0)
        return false;

    w2 /= 3;
    w1 = a + w2;
    w3 = b + w2;

    ll w = n / 3;

    return 0 <= w1 && w1 <= w &&
           0 <= w2 && w2 <= w &&
           0 <= w3 && w3 <= w &&
           (w - w1) + (w - w2) + (w - w3) == n - k;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d", &T);

    while (T--) {
        scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
        temp = 0;

        temp += check(d1, d2);
        temp += check(d1, -d2);
        temp += check(-d1, d2);
        temp += check(-d1, -d2);
        
        puts(temp ? "yes" : "no");
    }

    return 0;
}
