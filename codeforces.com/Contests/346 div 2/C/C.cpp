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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN];
vector <int> ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int ptr = 0;

    for (int i = 1; i <= m; i++) {
        if (ptr < n && a[ptr] == i) {
            ptr++;
        } else {
            ans.push_back(i);
            m -= i;
        }
    }

    printf("%d\n", (int)ans.size());
    for (int x: ans) {
        printf("%d ", x);
    }

    puts("");

    return 0;
}
