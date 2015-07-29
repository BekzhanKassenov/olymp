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

char s[MAXN];
int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);

    for (int i = 0; i < n - 1; i++) {
        if ((s[i] - '0') % 2 == 0 && s[n - 1] > s[i]) {
            swap(s[n - 1], s[i]);
            puts(s);
            return 0;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if ((s[i] - '0') % 2 == 0) {
            swap(s[n - 1], s[i]);
            puts(s);
            return 0;
        }
    }

    puts("-1");

    return 0;
}
