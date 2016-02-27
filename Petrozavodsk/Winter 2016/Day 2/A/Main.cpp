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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN], t[MAXN], buf[MAXN];

bool has(char s[], char sub[]) {
    int ptrs = 0, ptrsub = 0;

    int lens = strlen(s), lensub = strlen(sub);

    while (ptrs < lens && ptrsub < lensub) {
        while (ptrs < lens && s[ptrs] != sub[ptrsub]) {
            ptrs++;
        }

        if (ptrs >= lens || s[ptrs] != sub[ptrsub]) {
            return false;
        }

        ptrs++, ptrsub++;
    }

    return ptrsub == lensub;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s);
    gets(t);

    int len = strlen(s);
    int buflen;
    
    buflen = 0;
    for (int i = 0; i < len; i += 2) {
        buf[buflen++] = s[i];
    }

    buf[buflen] = '\0';
    
    if (has(t, buf)) {
        puts("Yes");
        return 0;
    }

    buflen = 0;
    for (int i = 1; i < len; i += 2) {
        buf[buflen++] = s[i];
    }
    
    buf[buflen] = '\0';

    if (has(t, buf)) {
        puts("Yes");
        return 0;
    }

    puts("No");


    return 0;
}
