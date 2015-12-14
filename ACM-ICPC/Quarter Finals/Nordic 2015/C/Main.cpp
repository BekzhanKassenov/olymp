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
const int MAXN = 310;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char pattern[] = "PER";
char s[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s);

    int ans = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != pattern[i % 3]) {
            ans++;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
