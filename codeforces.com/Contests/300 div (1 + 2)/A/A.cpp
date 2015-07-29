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

char s[MAXN];
char t[] = "CODEFORCES";
int n, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);
    k = strlen(t);

    if (n <= k) {
        puts("NO");
        return 0;
    }

    int diff = n - k;

    for (int l = 0; l + diff - 1 < n; l++) {
        int pos = 0;
        bool flag = true;

        for (int i = 0; i < l; i++) {
            if (s[i] != t[pos]) {
                flag = false;
            }

            pos++;
        }

        for (int i = l + diff; i < n; i++) {
            if (s[i] != t[pos]) {
                flag = false;
            }
            pos++;
        }

        if (flag) {
            puts("YES");
            return 0;
        }
    }

    puts("NO"); 

    return 0;
}
