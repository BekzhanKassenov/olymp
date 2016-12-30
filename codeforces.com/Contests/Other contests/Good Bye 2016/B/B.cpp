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
int k;
char dir[7];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> k >> dir;

        if (strcmp(dir, "North") == 0) {
            cur -= k;
            if (cur < 0) {
                puts("NO");
                return 0;
            }
        } else if (strcmp(dir, "South") == 0) {
            cur += k;
            if (cur > 20000) {
                puts("NO");
                return 0;
            }
        } else {
            if (cur == 0 || cur == 20000) {
                puts("NO");
                return 0;
            }
        }
    }

    if (cur != 0) {
        puts("NO");
    } else {
        puts("YES");
    }

    return 0;
}
