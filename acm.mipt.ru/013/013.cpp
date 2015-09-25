#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1010;

struct Box {
    int x, y, z;

    void read() {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        x = min(min(a, b), c);
        z = max(max(a, b), c);

        y = a + b + c - x - z;
    }

    bool canContain(const Box& b) {
        return x > b.x && y > b.y && z > b.z;
    }
};

int n;
Box b[MAXN];
bool g[MAXN][MAXN];
bool used[MAXN];
int mt[MAXN];

bool kuhn(int v) {
    if (used[v]) {
        return false;
    }

    used[v] = true;
    for (int i = 0; i < n; i++) {
        if (g[v][i] && (mt[i] == -1 || kuhn(mt[i]))) {
            mt[i] = v;
            return true;
        }
    }

    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        b[i].read();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i].canContain(b[j])) {
                g[i][j] = true;
            }
        }
    }

    memset(mt, 255, sizeof mt);
    
    for (int i = 0; i < n; i++) {
        if (kuhn(i)) {
            memset(used, false, sizeof used);
        }
    }

    int ans = n;

    for (int i = 0; i < n; i++) {
        if (mt[i] != -1) {
            ans--;
        }
    }

    printf("%d\n", ans);

    return 0;
}
