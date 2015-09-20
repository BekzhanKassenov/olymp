/****************************************
**          Solution by NU #2          **
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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, suma, sumb;
pair <int, int> a[MAXN], b[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
        suma += a[i].first;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i].first);
        b[i].second = i;
        sumb += b[i].first;
    }

    sort(a, a + n);
    sort(b, b + n);

    if (suma < sumb) {
        reverse(a, a + n);
    } else {
        reverse(b, b + n);
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", a[i].second + 1, b[i].second + 1);
    }
    
    return 0;
}
