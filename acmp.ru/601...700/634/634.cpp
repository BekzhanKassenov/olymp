#include <iostream>
#include <cstdio>

using namespace std;

int n, k;
int a[10][10], t[10];
int city[10], stck[10], ans;
bool used[10];

void go(int pos = 0, int sum = 0) {
    if (sum > ans)
        return;

    if (pos == k) {
        if (sum < ans) {
            for (int i = 0; i < k; i++)
                city[i] = stck[i];
            
            ans = sum;
        }

        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            int tsum = sum + t[i];

            if (pos)
                tsum += a[stck[pos - 1]][i];

            stck[pos] = i;
            go(pos + 1, tsum);
            used[i] = false;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            ans += a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        ans += t[i];
    }

    go();

    printf("%d\n", ans);

    for (int i = 0; i < k; i++) {
        printf("%d ", city[i] + 1);
    }

    return 0;
}
