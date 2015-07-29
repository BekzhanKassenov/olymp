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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
pair <int, int> a[maxn], longest = make_pair(INF, -1);

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d\n", &a[i].first, &a[i].second);

        longest.first = min(longest.first, a[i].first);
        longest.second = max(longest.second, a[i].second);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == longest) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    puts("-1");

    return 0;
}
