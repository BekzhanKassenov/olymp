/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char to[256];
char s1[30], s2[30];
char s[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s1);
    gets(s2);
    gets(s);

    for (int i = 0; i < 256; i++) {
        to[i] = i;
    }

    for (int i = 0; i < 26; i++) {
        to[tolower(s1[i])] = tolower(s2[i]);
        to[toupper(s1[i])] = toupper(s2[i]);
    }

    for (int i = 0; s[i]; i++) {
        putchar(to[s[i]]);
    }
    putchar('\n');
    
    return 0;
}
