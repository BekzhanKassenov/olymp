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

int n;
int min1, max1, cnt1;
int min2, max2, cnt2;
int min3, max3, cnt3;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    scanf("%d%d", &min1, &max1);
    scanf("%d%d", &min2, &max2);
    scanf("%d%d", &min3, &max3);

    cnt1 = min1;
    cnt2 = min2;
    cnt3 = min3;

    int diff;
    
    diff = min(n - cnt1 - cnt2 - cnt3, max1 - min1);
    cnt1 += diff;
    
    diff = min(n - cnt1 - cnt2 - cnt3, max2 - min2);
    cnt2 += diff;

    diff = min(n - cnt1 - cnt2 - cnt3, max3 - min3);
    cnt3 += diff;

    printf("%d %d %d\n", cnt1, cnt2, cnt3);

    return 0;
}
