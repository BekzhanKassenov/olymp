#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 70000;

int t[2 * maxn], pos[maxn], x, n, m;

void update(int pos, int val) {
    for (int i = pos; i < 2 * maxn; i |= (i + 1))
        t[i] += val;
}

int get(int pos) {
    int res = 0;

    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &m);

    for (int i = 1; i <= n; i++) {
        pos[i] = i + maxn;
        update(i + maxn, 1);
    }

    int nval = maxn;

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        
        int ans = get(pos[x]);

        update(pos[x], -1);
        pos[x] = nval--;
        update(pos[x], 1);

        printf("%d ", ans);
    }

    return 0;
}