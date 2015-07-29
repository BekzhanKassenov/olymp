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
typedef unsigned int uint;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN], t[MAXN];
bool ok;

bool equiv(char *ss, char *tt, int len) {
    ok = true;

    char *ptrs = ss;
    char *ptrt = tt;

    for (register int i = 0; i < len && ok; ++i, ++ptrs, ++ptrt) {
        ok &= *ptrs == *ptrt;
    }

    if (ok) {
        return true;
    }

    if (len & 1) {
        return false;
    }

    int half = len >> 1;

    bool result = (equiv(ss, tt, half) && equiv(ss + half, tt + half, half)) ||
                  (equiv(ss, tt + half, half) && equiv(ss + half, tt, half));

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    gets(t);

    if (equiv(s, t, strlen(s))) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}