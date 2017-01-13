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
int cnt[256];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);

    for (char c : s) {
        cnt[c]++;
    }

    int ans = cnt['B'];
    ans = min(ans, cnt['u'] / 2);
    ans = min(ans, cnt['l']);
    ans = min(ans, cnt['b']);
    ans = min(ans, cnt['a'] / 2);
    ans = min(ans, cnt['s']);
    ans = min(ans, cnt['r']);

    printf("%d\n", ans);

    return 0;
}
