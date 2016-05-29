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
const int MAXN = 3010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char s1[MAXN], s2[MAXN], t[MAXN];
int len[MAXN][MAXN];

char inv(char c) {
    int code = c - 'a';
    code = 25 - code;
    return code + 'a';
}

int solve(char s[], char t[]) {
    int mx = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == t[0]) {
            len[i][0] = 1;
        } else {
            len[i][0] = 0;
        }

        mx = max(mx, len[i][0]);
    }

    for (int i = 0; i < m; i++) {
        if (t[i] == s[0]) {
            len[0][i] = 1;
        } else {
            len[0][i] = 0;
        }

        mx = max(mx, len[0][i]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i] == t[j]) {
                len[i][j] = len[i - 1][j - 1] + 1;
            } else {
                len[i][j] = 0;
            }

            mx = max(mx, len[i][j]);
        }
    }

    return n + m - 2 * mx;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s1);
    gets(t);

    n = strlen(s1) - 1;
    m = strlen(t) - 1;

    strcpy(s2, s1);
    for (int i = 0; i < n; i++) {
        s2[i] = inv(s2[i]);
    }

    printf("%d\n", min(solve(s1, t), solve(s2, t) + 1));
        
    return 0;
}
