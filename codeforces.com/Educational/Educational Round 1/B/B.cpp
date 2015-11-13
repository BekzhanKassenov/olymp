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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN];
int m, l, r, k;
char buf[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s + 1);

    scanf("%d", &m);

    while (m--) {
        scanf("%d%d%d", &l, &r, &k);
        int len = (r - l + 1);
        k %= len;

        memcpy(buf, s + r - k + 1, sizeof(char) * k);
        memcpy(buf + k, s + l, sizeof(char) * (len - k));

        memcpy(s + l, buf, sizeof(char) * len);
    }

    puts(s + 1);

    return 0;
}
