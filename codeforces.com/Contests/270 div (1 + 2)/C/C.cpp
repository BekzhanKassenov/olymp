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

char mem[MAXN * 110];
char *cur;
int n, x;
pair <char*, char*> temp[MAXN], a[MAXN];
bool dp[MAXN][2];

void movecur() {
    while (*cur != '\0')
        cur++;

    cur++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    cur = mem;

    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%s", cur);
        temp[i].first = cur;
        movecur();

        scanf("%s", cur);
        temp[i].second = cur;
        movecur();
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[i] = temp[x];
    }

    dp[1][0] = dp[1][1] = true;

    for (int i = 2; i <= n; i++) {
        if (dp[i - 1][0] && strcmp(a[i - 1].first, a[i].first) < 0)
            dp[i][0] = true;

        if (dp[i - 1][1] && strcmp(a[i - 1].second, a[i].first) < 0)
            dp[i][0] = true;

        if (dp[i - 1][0] && strcmp(a[i - 1].first, a[i].second) < 0)
            dp[i][1] = true;

        if (dp[i - 1][1] && strcmp(a[i - 1].second, a[i].second) < 0)
            dp[i][1] = true;
    }

    if (dp[n][0] || dp[n][1]) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}
