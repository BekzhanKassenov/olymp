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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int f(char a[], char b[]) {
    int ans = 0;
    for (int i = 0; a[i] && b[i]; i++) {
        ans += a[i] != b[i];
    }

    return ans;
}

char get_other(char c1, char c2) {
    for (char c = 'a'; c <= 'z'; c++) {
        if (c != c1 && c != c2) {
            return c;
        }
    }

    return '\0';
}

char a[MAXN], b[MAXN], c[MAXN];
int n, t;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &t);

    gets(a);
    gets(b);

    if (t >= f(a, b)) {
        int diff = t - f(a, b);

        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                if (diff > 0) {
                    diff--;
                    c[i] = get_other(a[i], b[i]);
                } else {
                    c[i] = a[i];
                }
            } else {
                c[i] = get_other(a[i], b[i]);
            }
        }
    } else {
        int ta = f(a, b) - t, tb = f(a, b) - t;

        if (ta + tb > f(a, b)) {
            puts("-1");
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                c[i] = a[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (ta > 0) {
                    c[i] = a[i];
                    ta--;
                } else if (tb > 0) {
                    c[i] = b[i];
                    tb--;
                } else {
                    c[i] = get_other(a[i], b[i]);
                }
            }
        }
    }

    puts(c);

    return 0;
}
