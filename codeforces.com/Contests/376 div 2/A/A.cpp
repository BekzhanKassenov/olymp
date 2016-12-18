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

int dist(char a, char b) {
    a = a - 'a';
    b = b - 'a';

    int dist = abs(a - b);

    return min(dist, 26 - dist);
}

char s[110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    char prev = 'a';
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        ans += dist(prev, s[i]);
        prev = s[i];
    }

    printf("%d\n", ans);

    return 0;
}
