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

int n, k, size;
int ans, cnt, pos1;
vector <int> a[MAXN];
bool not_open[MAXN], not_close[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= k; i++) {
        scanf("%d", &size);
        a[i].resize(size);

        for (int j = 0; j < size; j++) {
            scanf("%d", &a[i][j]);
        }

        if (a[i][0] == 1) {
            pos1 = i;
        }
    }

    cnt = a[pos1].size();
    ans = cnt - 1; 

    assert(pos1 != 0);

    for (size_t j = 1; j < a[pos1].size() && a[pos1][j] - a[pos1][0] == (int)j; j++) {
        ans--;
        cnt--;
    }

    for (int i = 1; i <= k; i++) {
        if (i != pos1) {
            ans += a[i].size() - 1;
            cnt += a[i].size();
        }
    }

    ans += cnt - 1;

    printf("%d\n", ans);

    return 0;
}
