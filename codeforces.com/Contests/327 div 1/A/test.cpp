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

int n, a[MAXN];

void make(int a[]) {
    static int buf[MAXN];

    buf[1] = a[1];
    buf[n] = a[n];

    for (int i = 2; i < n; i++) {
        buf[i] = a[i - 1] + a[i] + a[i + 1] - min(min(a[i - 1], a[i]), a[i + 1]) - max(max(a[i - 1], a[i]), a[i + 1]);
    }

    memcpy(a, buf, sizeof(a[0]) * n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[j];
        }

        cout << endl;
        make(a);
    }

    return 0;
}
