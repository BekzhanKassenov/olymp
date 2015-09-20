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

char s[MAXN], t[MAXN];
int spos, tpos, ans;

bool ok(char c) {
    return c == 'R' || c == 'F';
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s);
    gets(t);

    while (s[spos] && t[tpos]) {
        if (s[spos] == 'L' && t[tpos] == 'L') {
            spos++, tpos++;
        } else {
            if (s[spos] == 'L') {
                tpos++;
            } else if (t[tpos] == 'L') {
                spos++;
            } else {
                tpos++, spos++;
            }
        }

        ans++;
    }

    while (s[spos]) {
        ans++, spos++;
    }

    while (t[tpos]) {
        ans++, tpos++;
    }
    
    printf("%d\n", ans);

    return 0;
}
