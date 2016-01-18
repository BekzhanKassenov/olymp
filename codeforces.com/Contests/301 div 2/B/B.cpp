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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, p, x, y;
int a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);

    int l = 1, r = n;
    int mid = (l + r) / 2;

    for (int i = 0; i < k; i++) {
        int val;
        scanf("%d", &val);
        if (val < y) {
            a[l++] = val;
        } else {
            a[r--] = val;
        }
    }

    if (a[mid] != 0 && a[mid] < y) {
        puts("-1");
        return 0;
    }

    vector <int> ans;
    while (l < mid && l <= r) {
        a[l++] = 1;
        ans.push_back(1);
    }

    while (r >= mid && l <= r) {
        a[r--] = y;
        ans.push_back(y);
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }

    if (sum > x) {
        puts("-1");
        return 0;
    }

    for (int num: ans) {
        printf("%d ", num);
    }

    puts("");

    return 0;
}
