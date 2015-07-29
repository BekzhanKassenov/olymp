/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, k, col, x, last, cnt, ans;
vector <PII> a;

int make(int i) {
    if (a[i].S < 2)
        return 0;

    int res = a[i].S;
    int l = i - 1, r = i + 1;

    while (l >= 0 && r < (int)a.size() && a[l].F == a[r].F && a[l].S + a[r].S >= 3) {
        res += a[l].S + a[r].S;
        l--, r++;
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &k, &x);

    scanf("%d", &col);
    last = col;
    cnt = 1;

    for (int i = 1; i < n; i++) {
        scanf("%d", &col);

        if (col == last)
            cnt++;
        else {
            a.push_back(MP(last, cnt));
            last = col;
            cnt = 1;
        }
    }

    a.push_back(MP(last, cnt));

    for (size_t i = 0; i < a.size(); i++) {
        if (a[i].F == x) {
            ans = max(ans, make(i));
        }
    }

    printf("%d", ans);

    return 0;
}
