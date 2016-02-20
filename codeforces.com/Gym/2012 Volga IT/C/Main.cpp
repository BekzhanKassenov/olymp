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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    set <int> songs(a, a + m);

    if ((int)songs.size() != m) {
        puts("No");
        return 0;
    }

    for (int i = m; i < n; i++) {
        songs.erase(a[i - m]);
        songs.insert(a[i]);

        if ((int)songs.size() != m) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}
