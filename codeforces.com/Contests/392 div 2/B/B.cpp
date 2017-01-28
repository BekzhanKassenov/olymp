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

int n;
char s[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);

    for (char c : {'R', 'B', 'Y', 'G'}) {
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                pos = i;
                break;
            }
        }

        int ans = 0;
        for (int i = pos % 4; i < n; i += 4) {
            if (s[i] == '!') {
                ans++;
            }
        }

        printf("%d ", ans);
    }
    puts("");

    return 0;
}
