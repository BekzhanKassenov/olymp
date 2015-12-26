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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char buf[MAXN], s[3 * MAXN];
int z[3 * MAXN];
int n, len;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(buf);
    len = strlen(buf);

    strcpy(s, buf);
    strcat(s, "#");
    strcat(s, buf);
    strcat(s, buf);

    n = strlen(s);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < len; i++) {
        int pos = len + 1 + i;
        if (z[pos] == len) {
            continue;
        }

        int diff = pos + z[pos];

        if (s[diff] < s[z[pos]]) {
            cnt++;
        }
    }

    printf("%d\n", cnt + 1);
    
    return 0;
}
