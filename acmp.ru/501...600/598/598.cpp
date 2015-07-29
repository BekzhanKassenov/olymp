#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int ans = 0, n, x;
bool fr[20][20];
int bitcount[1 << 15];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            fr[i][j] = x;
        }
    }

    bitcount[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                bitcount[mask] = bitcount[mask ^ (1 << i)] + 1;
                break;
            }
        } 

        bool flag = true;

        for (int i = 0; i < n && flag; i++) {
            if (!(mask & (1 << i)))
                continue;

            for (int j = 0; j < n && flag; j++) {
                if (!(mask & (1 << j)))
                    continue;

                if (!fr[i][j])
                    flag = false;
            }
        }

        if (flag && bitcount[ans] < bitcount[mask] && bitcount[mask] <= 5)
            ans = mask;
    }

    printf("%d\n", n - bitcount[ans] + 1);

    int num = 2;

    for (int i = 0; i < n; i++) {
        if (ans & (1 << i))
            printf("1 ");
        else {
            printf("%d ", num);
            num++;
        }
    }

    return 0;
}
