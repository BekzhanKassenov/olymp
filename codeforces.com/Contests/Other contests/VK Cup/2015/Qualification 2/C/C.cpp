/****************************************
**      Solution by NU: Black Kex      **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define left lllleft
#define right rrrright

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXS = 1010;
const int MAXT = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXS];
char t[MAXT];
int next[MAXT][26], prev[MAXT][26];
int cur[26];
int n, m, ans;
int left = -1, right = -1;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    gets(t);

    n = strlen(s);
    m = strlen(t);

    memset(cur, 255, sizeof cur);
    for (int i = m - 1; i >= 0; i--) {
        memcpy(next[i], cur, sizeof cur);
        cur[t[i] - 'a'] = i;
    }

    memset(cur, 255, sizeof cur);
    for (int i = 0; i < m; i++) {
        memcpy(prev[i], cur, sizeof cur);
        cur[t[i] - 'a'] = i;
    }

    // left
    int curpos = 0;
    if (s[0] != t[0]) {
        curpos = next[0][s[0] - 'a'];
    }

    for (int i = 1; i < n && curpos != -1; i++) {
        curpos = next[curpos][s[i] - 'a'];
    }

    if (curpos != -1) {
        left = curpos;
    }

    // right
    curpos = m - 1;
    if (s[n - 1] != t[m - 1]) {
        curpos = prev[m - 1][s[n - 1] - 'a'];
    }

    for (int i = n - 2; i >= 0 && curpos != -1; i--) {
        curpos = prev[curpos][s[i] - 'a'];
    }

    if (curpos != -1) {
        right = curpos;
    }

    if (left != -1 && right != -1 && left < right) {
        ans = right - left;
    }

    printf("%d\n", ans);

    return 0;
}
