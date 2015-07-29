/****************************************
**          Solution by NU #2          **
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
const int MAXN = 200020;
const int MAXM = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, pos;
int na, nb, x;
bool a[MAXN], b[MAXN];
int res[MAXN], last;
char s[MAXM];
int cas;

int factor();
int term();
int val();

int val() {
    int res = 0;

    if (pos >= m)
        return res;

    if (s[pos] == 'A') {
        pos++;
        res = 12;
    } else if (s[pos] == 'B') {
        pos++;
        res = 10;
    } else if (s[pos] == '(') {
        pos++;
        res = term();
        pos++;
    } else if (s[pos] == '-') {
        pos += 2;
        res = term();
        pos++;
        res ^= 0xf;
    }

    return res;
}

int factor() {
    int res = val();

    while (pos < m && s[pos] == '*') {
        pos++;
        res &= val();
    }

    return res;
}

int term() {
    int res = factor();

    while (pos < m && s[pos] == '+') {
        pos++;
        res |= factor();
    }

    return res; 
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%d %d\n", &n, &m) == 2 && (n || m)) {
        for (int i = 1; i <= n; i++)
            a[i] = b[i] = false;
        cas++;
        last = pos = 0;

        scanf("%d", &na);
        for (int i = 0; i < na; i++) {
            scanf("%d", &x);
            a[x] = true;
        }

        scanf("%d\n", &nb);
        for (int i = 0; i < nb; i++) {
            scanf("%d\n", &x);
            b[x] = true;
        }

        gets(s);

        int mask = factor();

        for (int i = 1; i <= n; i++) {
            if ((a[i] &&  b[i] && (mask & 8)) ||
               (!a[i] &&  b[i] && (mask & 2)) ||
               ( a[i] && !b[i] && (mask & 4)) ||
               (!a[i] && !b[i] && (mask & 1)))
                      
                res[last++] = i;
        }

        printf("Case %d: %d", cas, last);

        for (int i = 0; i < last; i++)
            printf(" %d", res[i]);

        puts("");
    }

    return 0;
}
