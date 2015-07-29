#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10010;

template <typename T>
T abs(T n) {
    return (n < 0) ? -n : n;
}

struct Coin {
    int val;
    bool sign;

    void set_num(int n) {
        if (n > 0) {
            val = n;
            sign = false;
        } else {
            val = -n;
            sign = true;
        }
    }
};

Coin a[MAXN], b[MAXN];
int n, k, x;
int missing;
int flipcnt;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i].set_num(x);

        missing ^= a[i].val;
    }

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &x);
        b[i].set_num(x);

        missing ^= b[i].val;
    }

    for (int i = 0; i < k; i++) {
        scanf("%d", &x);

        if (abs(x) == missing) {
            flipcnt++;
        }
    }

    flipcnt &= 1; 

    for (int i = 0; i < n; i++) {
        if (a[i].val == missing) {
            flipcnt ^= a[i].sign;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (b[i].val == missing) {
            flipcnt ^= b[i].sign;
        }
    }

    if (flipcnt) {
        putchar('-');
    }

    printf("%d\n", missing);

    return 0;
}
                          