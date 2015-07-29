#include <iostream>
#include <cstdio>

using namespace std;

int n, dp[60][60];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int age = 1; age < n; age++) {
            for (int j = max(age - 2, 0); j <= min(n - 1, age + 2); j++) {
                if (j != age)
                    dp[i][age] += dp[i - 1][j];
            }

            cout << i << ' ' << age << ' ' << dp[i][age] << endl;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans += dp[n - 1][i];

    printf("%d\n", ans);

    return 0;
}
