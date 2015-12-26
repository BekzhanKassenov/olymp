#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 300010;

int n, len;
int h[MAXN];
int t[2 * MAXN];

void build() {
    int power = 0;

    while ((1 << power) <= n) {
        power++;
    }

    len = 1 << power;

    for (int i = 0; i < n; i++) {
        t[i + len] = h[i];
    }

    for (int i = len - 1; i >= 0; i--) {
        t[i] = max(t[2 * i], t[2 * i + 1]);
    }
}

int get_max(int l, int r) {
    l += len, r += len;

    int ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans = max(ans, t[l]);
            l++;
        }

        if (!(r & 1)) {
            ans = max(ans, t[r]);
            r--;
        }

        l >>= 1;
        r >>= 1;
    }

    return ans;
}

int main() {
    freopen("mushrooms.in", "r", stdin);
    freopen("mushrooms.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    build();

    int m;
    scanf("%d", &m);

    int l, r;
    scanf("%d%d", &l, &r);

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int height = get_max(l, r);
        ans += height;

        int ll = min(r, int((1ll * l * height + 1ll * height * height) % n));
        int rr = max(r, int((1ll * l * height + 1ll * height * height) % n));

        l = ll, r = rr;
    }

    printf("%I64d\n", ans);

    return 0;
}
