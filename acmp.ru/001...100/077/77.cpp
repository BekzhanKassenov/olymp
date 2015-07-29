#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, k, l = 1;
int C[33][33], dp[33][33];

void show(int n) {
    while (n) {
        cout << (n & 1);
        n >>= 1;
    }

    cout << endl;
}

int get_log(int n) {
    int result = 0;

    for (int i = 0; i < 31; i++) {
        if ((1 << i) < n) {
            result = i;
        }
    }

    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    if (k >= 32) {
        puts("0");
        return 0;
    }

    for (int i = 0; i < 33; i++) {
        C[i][0] = C[i][i] = 1;

        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }

    memset(dp, 255, sizeof dp);
    int len = get_log(n);

    for (int i = len; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            
        }
    }

    printf("%d\n", );

    return 0;
}
