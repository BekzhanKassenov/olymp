#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 200010;

int t[MAXN];

int sum(int pos) {
    int result = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        result += t[i];
    }

    return result;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void update(int pos, int val) {
    for (int i = pos; i < MAXN; i |= i + 1) {
        t[i] += val;
    }
}

int main() {
    freopen("floor4.in", "r", stdin);
    freopen("floor4.out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (x < 0) {
            update(-x, -1);
        } else {
            if (sum(x, x) == 0) {
                printf("%d\n", x);
                update(x, 1);
            } else {
                int l = x, r = MAXN - 1;

                int ans = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (sum(x, mid) == mid - x + 1) {
                        ans = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }

                ans++;
                printf("%d\n", ans);
                update(ans, 1);
            }
        }
    }

    return 0;
}
