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

int n, a[4];
int b[4];
int c[4];
int last;

bool matches() {
    int posa = 0;
    last = 0;
    for (int i = 0; i < 4; i++) {
        if (posa < n && a[posa] == b[i]) {
            posa++;
        } else {
            c[last++] = b[i];
        }
    }

    return posa == n;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    for (int x = 1; x <= 500; x++) {
        for (int y = x; y <= 3 * x; y++) {
            b[0] = x;
            b[1] = y;
            b[2] = 4 * x - y;
            b[3] = 3 * x;

            if (matches()) {
                puts("YES");

                for (int i = 0; i < last; i++) {
                    printf("%d\n", c[i]);
                }
                return 0;
            }
        }
    }

    puts("NO");
    
    return 0;
}
