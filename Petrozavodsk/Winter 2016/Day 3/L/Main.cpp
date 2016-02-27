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
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN], t[MAXN];
int ns, nt;

bool check(char s[], char t[]) {
    int ptrs = 0, ptrt = 0;

    while (ptrs < ns && ptrt < nt) {
        while (ptrt < nt && s[ptrs] != t[ptrt]) {
            ptrt++;
        }

        if (s[ptrs] == t[ptrt]) {
            ptrs++, ptrt++;
        }
    }

    return ptrs == ns;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s);
    gets(t);

    ns = strlen(s);
    nt = strlen(t);

    if (!check(s, t)) {
        puts("No");
        return 0;
    }

    int prefs = 1, preft = 1;

    while (prefs < ns && s[prefs] == s[0]) {
        prefs++;
    }

    while (preft < nt && t[preft] == t[0]) {
        preft++;
    }

    if (preft > prefs || s[0] != t[0]) {
        puts("No");
        return 0;
    }

    puts("Yes");
    
    return 0;
}
