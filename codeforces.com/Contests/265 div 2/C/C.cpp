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

char s[1010], lim;
int n, p;

bool check(int pos) {
    if (pos == 0)
        return true;

    if (pos == 1)
        return s[0] != s[1];

    return s[pos] != s[pos - 1] && s[pos] != s[pos - 2] && s[pos - 2] != s[pos - 1];
}

void update(int pos) {
    if (pos < 0) {
        puts("NO");
        exit(0);
    }

    for (char cc = s[pos] + 1; cc <= lim; cc++) {
        s[pos] = cc;
        if (check(pos))
            return;
    }

    s[pos] = 'a';
    update(pos - 1);

    for (char cc = s[pos]; cc <= lim; cc++) {
        s[pos] = cc;
        if (check(pos))
            return;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d %d\n", &n, &p);
    gets(s);

    lim = 'a' + p - 1;

    if (p == 1) {
        puts("NO");
        return 0;
    }

    if (n == 1) {
        s[0]++;
        if (s[0] > lim)
            puts("NO");
        else
            puts(s);
        return 0;
    }

    update(n - 1);
    puts(s);

    return 0;
}
