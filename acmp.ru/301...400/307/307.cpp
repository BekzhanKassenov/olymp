#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 300;

int t[300][300], n, m, p, x, y, ans;

void upd(int row, int pos) {
    for (int i = pos; i <= m; i |= (i + 1)) {
        t[row][i]++;
    }
}

int sum(int row, int pos) {
    int res = 0;

    for (int i = pos; i > 0; i = (i & (i + 1)) - 1) {
        res += t[row][i];
    }

    return res;
}

int sum(int row, int l, int r) {
    if (l > r)
        return 0;

    return sum(row, r) - sum(row, l - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &p);

    for (int i = 0; i < p; i++) {
        scanf("%d%d", &x, &y);

        for (int j = 1; j < x; j++) {
            ans += sum(j, y + 1, m);
        }

        for (int j = x + 1; j <= n; j++) {
            ans += sum(j, 1, y - 1);
        }

        upd(x, y);
    }

    printf("%d\n", ans);

    return 0;
}
    