#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 30010;
int n;
int a[MAXN];
long long cur, ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    if (n == 1) {
        printf("%d\n", a[0]);
        return 0;
    }

    if (n == 2) {
        printf("%d\n", a[0] + a[1]);
        return 0;
    }
    
    cur = a[n - 1] + a[n - 2];
    ans = cur;
    int l = n - 3, r = n - 1;

    while (l >= 0) {
        while (r >= l && a[l] + a[l + 1] < a[r]) {
            cur -= a[r];
            r--;
        }

        cur += a[l];
        ans = max(ans, cur);
        l--;
    }

    printf("%I64d\n", ans);

    return 0;   
}
