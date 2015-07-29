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

int n, cnt;
char s[MAXN], t[MAXN];
char res[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    gets(t);

    n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            res[i] = s[i];
        } else {
            cnt++;
        }
    }

    if (cnt & 1) {
        puts("impossible");
        return 0;
    }

    cnt /= 2;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (cnt > 0) {
                res[i] = s[i];
            } else {
                res[i] = t[i];
            }

            cnt--;
        }
    }

    puts(res);

    return 0;
}
