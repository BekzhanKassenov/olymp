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
const int MAXN = 60;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, l;
int a[MAXN], b[MAXN];

void check(int a[], int b[]) {
    for (int pos = 0; pos < n; pos++) {
        for (int addend = 0; addend <= l; addend++) {
            bool eq = true;
            for (int i = 0; i < n; i++) {
                if (a[i] != (b[(pos + i) % n] + addend) % l) {
                    eq = false;
                    break;
                }
            }

            if (eq) {
                puts("YES");
                exit(0);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    check(a, b);
    check(b, a);

    puts("NO");

    return 0;
}
