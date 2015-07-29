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
const long long INF = 1e18;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN], b[MAXN];

bool check(long long val) {
    memcpy(b, a, sizeof(int) * (n + 1));

    int ptr = 1;

    for (int i = 0; i < m && ptr <= n; i++) {
        long long _time = val - ptr;

        while (_time > 0 && ptr <= n) {
            if (b[ptr] <= _time) {
                _time -= b[ptr];
                b[ptr] = 0;
                ptr++;
                _time--;
            } else {
                b[ptr] -= _time;
                _time = 0;
            }
        }
    }

    while (ptr <= n && b[ptr] == 0) {
        ptr++;
    }

    return ptr > n;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    long long left = 0, right = INF;
    long long ans = INF;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
