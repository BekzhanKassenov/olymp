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

int T;
int a, b, c;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d", &a, &b, &c);

        if (a == 0 && b == 0) {
            if (c == 0) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else if (a == 0) {
            if (c % 2 == 0 && 2 * b >= c) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else if (b == 0) {
            if (a >= c) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else {
            int temp = c - a;

            if (temp % 2 == 1) {
                temp++;
            }

            if (2 * b >= temp) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    
    return 0;
}
