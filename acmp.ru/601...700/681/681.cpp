#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
long long ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    int k = sqrt(n + .0);
    ans = 2 * k * (k + 1);

    int rem = n - k * k;
    int cnt = rem / k;
    rem %= k;

    ans += cnt * (2 * k + 1);
    
    if (rem)
        ans += 2 * rem + 1;
    

    printf("%I64d\n", ans);

    return 0;
}
