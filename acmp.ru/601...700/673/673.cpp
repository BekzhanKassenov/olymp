#include <iostream>
#include <cstdio>

using namespace std;

int n, arr[30], mindig[30];
long long ans;

bool cmp() {
    for (int i = 0; i < n; i++) {
        if (arr[i] != mindig[i])
            return arr[i] < mindig[i];
    }

    return false;
}

void update() {
    if (cmp())
        memcpy(mindig, arr, sizeof arr);
}

void go(int pos = 0, int sum = 0, long long mul = 1) {
    if (pos == n) {
        if (sum == mul) {
            ans++;

            update();
        }

        return;
    }

    if (sum + (n - pos) * 9 < mul)
        return;

    for (int i = 1; i < 10; i++) {
        arr[pos] = i;
        go(pos + 1, sum + i, mul * i);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    if (n == 1) {
        puts("10 0");
        return 0;
    }

    for (int i = 0; i < n; i++)
        mindig[i] = 10;

    go();

    printf("%I64d ", ans);

    for (int i = 0; i < n; i++) {
        printf("%d", mindig[i]);
    }

    puts("");

    return 0;
}
