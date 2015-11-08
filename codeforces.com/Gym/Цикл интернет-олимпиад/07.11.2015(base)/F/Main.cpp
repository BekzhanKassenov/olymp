/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "minimal"

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

int pos[MAXN][26];
char s[MAXN];
int n, m;
int ql, qr;

int solve(int& num, int c) {
    if (pos[qr][c] < ql) {
        return 0;
    }

    int begin = num;
    int ans = 0;

    if (pos[qr][c] >= num) {
        ans += pos[qr][c] - num;
        num = pos[qr][c];
    }

    if (begin > ql && pos[begin - 1][c] >= ql) {
        ans += qr - num + pos[begin - 1][c] - ql + 1;
        num = pos[begin - 1][c];
    }

    return ans;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    memset(pos, 255, sizeof pos);

    gets(s);
    n = strlen(s);

    pos[0][s[0] - 'a'] = 0;
    for (int i = 1; i < n; i++) {
        memcpy(pos[i], pos[i - 1], sizeof(int) * 26);
        pos[i][s[i] - 'a'] = i;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &ql, &qr);

        ql--, qr--;
        int num = ql;
        long long ans = 0;
        for (int c = 0; c < 26; c++) {
            ans += solve(num, c);
        }

        printf("%I64d\n", ans);
    }

    return 0;
}