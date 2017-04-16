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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool win(int x, int y, int k) {
    return x >= k && x - y >= 2;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);

    while (T--) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);

        if (x < y) {
            swap(x, y);
        }

        int ans = 0;
        while (!win(x, y, k)) {
            x++;
            ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}
