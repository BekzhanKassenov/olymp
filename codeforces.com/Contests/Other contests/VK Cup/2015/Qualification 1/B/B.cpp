/****************************************
**      Solution by NU: Black Kex      **
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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int w[MAXN], h[MAXN];
long long sum_w;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &h[i]);
        sum_w += w[i];
    }

    multiset <int, greater <int> > set_h(h, h + n);

    for (int i = 0; i < n; i++) {
        set_h.erase(set_h.find(h[i]));
        sum_w -= w[i];

        printf("%I64d ", sum_w * (*set_h.begin()));
        
        sum_w += w[i];
        set_h.insert(h[i]);
    }

    puts("");

    return 0;
}
             4