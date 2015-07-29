#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 5010;

int n;
double dollar[maxn], euro[maxn], dp[maxn];    

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%lf%lf", dollar + i, euro + i);

    dp[0] = 100.0;

    for (int i = 1; i < n; i++) {
        double dol = dp[i - 1] / dollar[i - 1];
        dol *= dollar[i];

        double eur = dp[i - 1] / euro[i - 1];
        eur *= euro[i];

        dp[i] = max(dp[i - 1], max(dol, eur));
    }

    printf("%.2lf", dp[n - 1]);

    return 0;
}