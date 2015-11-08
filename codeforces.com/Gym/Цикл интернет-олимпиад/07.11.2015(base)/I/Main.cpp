/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "text"

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

int cnt[26] = {
    2, // A
    1, // B
    1, // C
    1, // D
    2, // E
    2, // F
    1, // G
    3, // H
    3, // I
    2, // J
    3, // K
    1, // L
    1, // M
    1, // N
    1, // O
    1, // P
    1, // Q
    2, // R
    1, // S
    2, // T
    1, // U
    1, // V
    1, // W
    2, // X
    2, // Y
    1  // Z
};

char s[1010];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    gets(s);

    int ans = 0;
    for (int i = 0; s[i]; i++) {
        ans += cnt[s[i] - 'A'];
    }

    printf("%d\n", ans);

    return 0;
}
