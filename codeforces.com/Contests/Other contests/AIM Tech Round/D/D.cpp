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

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int n;
int a[MAXN];
int dp[MAXN][3];
long long c1, c2;

long long solve(const vector <int>& pos) {
    multiset <long long> Set;

    for (size_t i = 0; i < pos.size(); i++) {
        long long num = (pos[i] - pos[0] + 1) * c1;
        num += (pos.size() - i - 1) * c2;

        Set.insert(num);
    }

    long long ans = min(c2 * pos.size(), *Set.begin());

    for (size_t i = 0; i < pos.size(); i++) {
        long long num = *Set.begin();
        num -= (pos[i] - pos[0]) * c1;
        num += (i + 1) * c2;

        ans = min(ans, num);

        Set.erase(Set.find((pos[i] - pos[0] + 1) * c1 + (pos.size() - i - 1) * c2));
    }

    return ans;
}

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%I64d%I64d", &n, &c1, &c2);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int g = a[0];
    for (int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
    }

    if (g != 1) {
        puts("0");
        return 0;
    }

    vector <int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            pos.push_back(i);
        }
    }

    long long ans = solve(pos);

    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = dp[i][2] = 1;
    }

    dp[0][0] = a[0];
    dp[0][1] = a[0] + 1;
    dp[0][2] = a[0] - 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(gcd(a[i], dp[i - 1][0]), gcd(a[i], dp[i - 1][1]), gcd(a[i], dp[i - 1][2]));
        dp[i][1] = max(gcd(a[i] + 1, dp[i - 1][0]), gcd(a[i] + 1, dp[i - 1][1]), gcd(a[i] + 1, dp[i - 1][2]));
        dp[i][2] = max(gcd(a[i] - 1, dp[i - 1][0]), gcd(a[i] - 1, dp[i - 1][1]), gcd(a[i] - 1, dp[i - 1][2]));                
    }

    int d= max(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]);
    
    if (d == 1 || d == 2) {
        printf("%I64d\n", ans);
        return 0;
    }

    pos.clear();
    for (int i = 0; i < n; i++) {
        if (a[i] % d != 0) {
            pos.push_back(i);
        }
    }

    ans = min(ans, solve(pos));

    printf("%I64d\n", ans);

    return 0;
}
