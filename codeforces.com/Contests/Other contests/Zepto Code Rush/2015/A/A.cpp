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
bool ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n; i++) {
            int pos = i;
            bool found = true;

            for (int num = 0; num < 5 && found; num++) {
                if (pos >= n || s[pos] != '*') {
                    found = false;
                }

                pos += len;
            }

            if (found) {
                ans = true;
            }
        }
    }

    if (ans) {
        puts("yes");
    } else {
        puts("no");
    }
    
    return 0;
}