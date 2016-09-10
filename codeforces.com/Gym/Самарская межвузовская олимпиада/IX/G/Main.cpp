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

int a, b, a1, b1, a2, b2;

bool check(int h1, int w1, int h2, int w2) {
    return (w1 + w2 <= a && max(h1, h2) <= b)
        || (h1 + h2 <= b && max(w1, w2) <= a);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &a, &b);
    scanf("%d%d", &a1, &b1);
    scanf("%d%d", &a2, &b2);

    if (check(a1, b1, a2, b2)
     || check(a1, b1, b2, a2)
     || check(b1, a1, a2, b2)
     || check(b1, a1, b2, a2)) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}
