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

vector <pair <int, int> > ans[300 * 300];
int n, m, k, last, x, y, cnt;
int dx = 0, dy = 1;
int ddx = 1, ddy = 0;

void add(int x, int y) {
    ans[last].push_back(MP(x, y));

    if (cnt % 2 == 1 && k > 1) {
        last++;
        k--;
    }

    cnt++; 
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);

    while (cnt < n * m) {
        add(x, y);

        int tx = x + dx;
        int ty = y + dy;

        if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
            x = tx, y = ty;
        } else {
            x += ddx;
            y += ddy;
            dx *= -1;
            dy *= -1;
        }
    }

    for (int i = 0; i <= last; i++) {
        printf("%u ", ans[i].size());

        for (size_t j = 0; j < ans[i].size(); j++) {
            printf("%d %d ", ans[i][j].F + 1, ans[i][j].S + 1);
        }

        puts("");
    }

    return 0;
}
