#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const long long ONE = 1ll;
const int MAXN = 55;
const int MAXD = 550000;

int n, k;
int input[MAXN];
long long dp[MAXD];
long long total;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        total += input[i];
    }

    vector <int> a;
    a.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input[i] < k) {
            a.push_back(input[i]);
        }
    }

    int gr = n - a.size();
    n = a.size();

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int sum = MAXD - a[i] - 1; sum >= 0; sum--) {
            dp[sum + a[i]] += dp[sum];
        }
    }

    long long ans = 0;
    if (gr > 0) {
        ans += ((ONE << gr) - 2) * (ONE << n);
        for (int i = k; i < MAXD; i++) {
            ans += 2 * dp[i];
        }
    } else {
        for (int i = k; i < MAXD && total - i >= k; i++) {
            ans += dp[i];
        }
    }

    printf("%lld\n", ans);

    return 0;
}
