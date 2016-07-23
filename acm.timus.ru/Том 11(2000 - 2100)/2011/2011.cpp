#include <iostream>
#include <cstdio>

using namespace std;

int n;
int cnt[3];
int power[110];

void factorize(int num, int delta) {
    for (int i = 2; i < 110; i++) {
        while (num % i == 0) {
            num /= i;
            power[i] += delta;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x - 1]++;
    }

    for (int i = 2; i <= n; i++) {
        factorize(i, 1);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 2; j <= cnt[i]; j++) {
            factorize(j, -1);
        }
    }

    int cur = 1;
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < power[i]; j++) {
            cur *= i;
            if (cur >= 6) {
                puts("Yes");
                return 0;
            }
        }
    }

    puts("No");
    return 0;
}
