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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, last;
char temp[5];
int ciel[MAXN], jiro[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s %d\n", temp, jiro + last);

        if (strcmp(temp, "ATK") == 0)
            last++;
    }

    n = last;

    for (int i = 0; i < m; i++) {
        scanf("%d", &ciel[i]);
    }

    sort(ciel, ciel + m);
    sort(jiro, jiro + n);

    int ans = 0;
    int curciel = m - 1, curjiro = 0;

    while (curciel >= 0 && curjiro < n && ciel[curciel] > jiro[curjiro]) {
        ans += ciel[curciel] - jiro[curjiro];
        curciel--;
        curjiro++;
    }

    printf("%d\n", ans);

    return 0;
}
