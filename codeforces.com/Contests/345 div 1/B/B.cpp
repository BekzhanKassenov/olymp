/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a, b, T;
long long cost[MAXN];
char s[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d%d\n", &n, &a, &b, &T);
    gets(s);

    for (int i = n; i < 2 * n; i++) {
        s[i] = s[i - n];
    }

    for (int i = 0; i < 2 * n; i++) {
        cost[i] = 1 + (s[i] == 'w') * b;
    }

    if (cost[0] > T) {
        puts("0");
        return 0;
    }

    int r = n;
    long long sum = cost[n];

    while (r + 1 < 2 * n && sum + a + cost[r + 1] <= T) {
        sum += a + cost[r + 1];
        r++;
    }

    int ans = min(n, r - n + 1);
    
    for (int i = n - 1; i >= 0; i--) {
        sum += cost[i] + 2 * a;
        
        while (r > n && sum > T) {
            sum -= a + cost[r];
            r--;
        }

        if (sum > T) {
            break;
        }

        ans = max(ans, min(n, r - i + 1));
    }

    int l = n;
    sum = cost[n];

    while (l > 0 && sum + a + cost[l - 1] <= T) {
        sum += a + cost[l - 1];
        l--;
    }

    ans = max(ans, min(n, n - l + 1));

    for (int i = n + 1; i < 2 * n; i++) {
        sum += cost[i] + 2 * a;
        
        while (l < n && sum > T) {
            sum -= a + cost[l];
            l++;
        }

        if (sum > T) {
            break;
        }

        ans = max(ans, min(n, i - l + 1));
    }

    printf("%d\n", ans);

    return 0;
}
