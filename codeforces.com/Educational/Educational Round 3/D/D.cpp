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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k, s;
int conv[2][MAXN];
int pref[2][MAXN];
vector <pair <int, int> > gadget[2];
vector <pair <int, int> > res;

bool check(int day) {
    res.clear();

    size_t ptr[2] = {0, 0};
    auto burl = [day, &ptr](int idx) {
        return 1ll * conv[idx][pref[idx][day]] * gadget[idx][ptr[idx]].first;
    };

    long long total = 0;
    auto use = [day, &total, &burl, &ptr](int idx) {
        total += burl(idx);
        res.emplace_back(gadget[idx][ptr[idx]].second, pref[idx][day]);
        ptr[idx]++;
    };

    for (int i = 0; i < k && total <= s; i++) {
        if (ptr[0] == gadget[0].size()) {
            use(1);
        } else if (ptr[1] == gadget[1].size()) {
            use(0);
        } else {
            use(burl(0) < burl(1) ? 0 : 1);
        }
    }

    return total <= s;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &n, &m, &k, &s);

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &conv[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        int type, cost;
        scanf("%d%d", &type, &cost);
        gadget[type - 1].emplace_back(cost, i + 1);
    }

    sort(all(gadget[0]));
    sort(all(gadget[1]));

    for (int i = 0; i < 2; i++) {
        pref[i][1] = 1;
        for (int j = 2; j <= n; j++) {
            pref[i][j] = j;
            if (conv[i][pref[i][j - 1]] < conv[i][j]) {
                pref[i][j] = pref[i][j - 1];
            }
        }
    }

    int l = 1, r = n;
    int ans = -1;
    vector <pair <int, int> > result;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            result = res;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d\n", ans);
    for (const auto& p : result) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}
