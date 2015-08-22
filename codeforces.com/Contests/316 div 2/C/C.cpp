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
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, x, res;
char s[MAXN], c;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);

    gets(s + 1);

    for (int i = 1; i + 1 <= n; i++) {
        if (s[i] == '.' && s[i] == s[i + 1]) {
            res++;
        }
    }

    while (m --> 0) {
        scanf("%d %c\n", &x, &c);

        if (s[x] == '.') {
            res -= (x > 1 && s[x] == s[x - 1]);
            res -= (s[x] == s[x + 1]);
        }

        s[x] = c;

        if (s[x] == '.') {
            res += (x > 1 && s[x] == s[x - 1]);
            res += (s[x] == s[x + 1]);
        }

        printf("%d\n", res);
    }
    
    return 0;
}
