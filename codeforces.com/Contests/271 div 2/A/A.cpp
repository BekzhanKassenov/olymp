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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char str[3][50] = {"qwertyuiop",
                   "asdfghjkl;",
                   "zxcvbnm,./"};

map <char, pair <int, int> > Map;
char c;
char s[110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 3; i++) {
        for (int j = 0; str[i][j]; j++) {
            Map[str[i][j]] = make_pair(i, j);
        }
    }

    scanf("%c\n", &c);
    gets(s);

    for (int i = 0; s[i]; i++) {
        int x = Map[s[i]].first;
        int y = Map[s[i]].second;

        if (c == 'R')
            y--;
        else
            y++;

        putchar(str[x][y]);
    }

    return 0;
}
