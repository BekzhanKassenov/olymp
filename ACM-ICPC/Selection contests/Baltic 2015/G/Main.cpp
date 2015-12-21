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

int n, x, m;
char s[MAXN], progr[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &x);
    
    gets(s + 1);

    scanf("%d\n", &m);
    gets(progr);

    putchar(s[x]);
    
    for (int i = 0; i < m; i++) {
        if (progr[i] == 'L') {
            x--;
        } else {
            x++;
        }

        putchar(s[x]);
    }

    puts("");

    return 0;
}
