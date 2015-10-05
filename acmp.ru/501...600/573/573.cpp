#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, v;

struct Meet {
    int t, x, y;

    bool operator < (const Meet& m) const {
        return t < m.t;
    }

    void read() {
        int a, b;

        scanf("%d:%d %d %d", &a, &b, &x, &y);

        t = a * 60 + b;
    }

    bool before(const Meet& m) {
        if (t > m.t) {
            return false;
        }

        int dist = sqr(x - m.x) + sqr(y - m.y);

        return (dist * 3600ll) <= 1ll * sqr(v) * sqr(m.t - t);
    }
};

Meet a[MAXN];
bool g[MAXN][MAXN];
bool used[MAXN];
int match[MAXN];

bool dfs(int v) {
    if (used[v]) {
        return false;
    }

    used[v] = true;
    for (int to = 0; to < n; to++) {
        if (!g[v][to]) {
            continue;
        }

        if (match[to] == -1 || dfs(match[to])) {
            match[to] = v;
            return true;
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &v);

    for (int i = 0; i < n; i++) {
        a[i].read();
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].before(a[j])) {
                g[i][j] = true;
            }
        }
    }

    memset(match, 255, sizeof match);
    for (int i = 0; i < n; i++) {
        memset(used, false, sizeof used);
        dfs(i);
    }

    int ans = n;
    for (int i = 0; i < n; i++) {
        if (match[i] != -1) {
            ans--;
        }
    }


    printf("%d\n", ans);

    return 0;
}
