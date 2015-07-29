/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "segredo"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char t[MAXN];
int cnt[26];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    gets(t);

    for (int i = 0; t[i]; i++) {
        cnt[t[i] - 'a']++;
    }
    
    int mx = 0, mn = MAXN;

    for (int i = 0; i < 26; i++)
        if (cnt[i]) {
            mx = max(mx, cnt[i]);
            mn = min(mn, cnt[i]);
        }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] == mx)
            putchar(i + 'a');
    }

    putchar('\n');

    for (int i = 0; i < 26; i++) {
        if (cnt[i] == mn)
            putchar(i + 'a');
    }

    return 0;
}
