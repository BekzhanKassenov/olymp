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
const int MAXN = 50010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int sign(int n) {
    return (n > 0) - (n < 0);
}

int n;
int a[MAXN];
int diff[MAXN];
int cntinc[MAXN], cntdec[MAXN];

bool incr(int l, int r) {
    if (l >= r) {
        return true;
    }
    
    
}

bool decr(int l, int r) {
    if (r >= l) {
        return true;
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i];
    }
    
    cntinc[0] = (diff[0] >= 0);
    cntdec[0] = (diff[0] <= 0);
    
    for (int i = 1; i < n - 1; i++) {
        cntinc[i] = cntinc[i - 1] + (diff[i] >= 0);
        cntdec[i] = cntdec[i - 1] + (diff[i] <= 0);
    }
    
    return 0;
}
