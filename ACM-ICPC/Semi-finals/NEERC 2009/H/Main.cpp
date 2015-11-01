/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "headshot"

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

char s[110];
int n;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    gets(s);
    n = strlen(s);

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt1++;
        }

        if (s[i] == '0' && s[(i + 1) % n] == '0') {
            cnt2++;
        }
    }

    if (sqr(cnt1) > n * cnt2) {
        puts("ROTATE");
    } else if (sqr(cnt1) < n * cnt2) {
        puts("SHOOT");
    } else {
        puts("EQUAL");
    }

    return 0;
}
