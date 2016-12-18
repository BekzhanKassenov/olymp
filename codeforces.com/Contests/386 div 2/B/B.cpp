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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN];
char ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);

    int pos = 0;

    int l, r;
    if (n % 2 == 1) {
        ans[n / 2] = s[pos++];
        l = n / 2 - 1, r = n / 2 + 1;
    } else {
        l = n / 2 - 1, r = n / 2;
    }

    while (pos < n) {
        ans[l--] = s[pos++];
        ans[r++] = s[pos++];
    }

    puts(ans);

    return 0;
}
