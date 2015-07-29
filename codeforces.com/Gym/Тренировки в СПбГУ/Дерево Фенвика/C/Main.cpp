/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "inverse"

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

int n, a[MAXN], b[MAXN];
int t[MAXN];
long long ans;

int sum(int l) {
    int result = 0;
    for (int i = l; i >= 0; i = (i & (i + 1)) - 1) {
        result += t[i];
    }

    return result;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void update(int pos) {
    for (int i = pos; i < n; i |= i + 1) {
        t[i]++;
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    memcpy(b, a, sizeof(int) * n);
    sort(b, b + n);

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b, b + n, a[i]) - b;
    }

    for (int i = 0; i < n; i++) {
        ans += sum(a[i], n - 1);
        update(a[i]);
    }

    printf("%I64d\n", ans);

    return 0;
}
