/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "bishops"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

inline long long sqr(int n) {
    return 1ll * n * n;
}

int n, m, C;
vector <pair <int, long long> > b[2][2 * MAXN];

int t[2 * MAXN];
int tn;

void reset(int n) {
    tn = 1;
    while (tn < n) {
        tn <<= 1;
    }

    memset(t, 0, sizeof(int) * (2 * tn + 10));
}

void setVal(int pos, int val) {
    pos += tn - 1;
    t[pos] = max(t[pos], val);
    for (int i = pos >> 1; i >= 1; i >>= 1) {
        t[i] = max(t[2 * i], t[2 * i + 1]);
    }
}

int getMax(int l, int r) {
    int res = 0;
    l += tn - 1;
    r += tn - 1;
    while (l <= r) {
        if (l & 1) {
            res = max(res, t[l]);
            l++;
        }

        if (!(r & 1)) {
            res = max(res, t[r]);
            r--;
        }

        l >>= 1, r >>= 1;
    }

    return res;
}   

int DP(const vector <pair <int, long long> >& vec) {
    /*
    a[i].s + a[j].s + C <= a[i].f - a[j].f + 1
    a[i].s - a[i].f + C1 <= -a[j].s - a[j].f
    a[i].f - a[i].s + C2 >= a[j].s + a[j].f
    */

    vector <long long> nums;
    for (const auto& p : vec) {
        nums.push_back(p.first + p.second);
    }

    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());

    auto getPos = [&](long long num) {
        return lower_bound(all(nums), num) - nums.begin();
    };

    reset(nums.size());

    set <long long> Set;

    for (const auto& p : vec) {
        int dp = 1;    
        auto it = Set.upper_bound(p.first - p.second + 1 - C);
        if (it != Set.begin()) {
            long long num = *(--it);
            dp += getMax(0, getPos(num));
        }

        long long val = p.first + p.second;
        Set.insert(val);
        setVal(getPos(val), dp);
    }

    return getMax(0, (int)nums.size() - 1);
}   

int main() {
    freopen(File".in", "r", stdin);
    
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d", &n, &m, &C);

        auto diagNum = [&](int x, int y) {
            int val = max(x, y) - min(x, y);
            if (x > y) {
                return n + val;
            }

            return val;
        };

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= 2 * n + 10; j++) {
                b[i][j].clear();
            }
        }

        for (int i = 0; i < m; i++) {
            int r, c, p;

            scanf("%d%d%d", &r, &c, &p);

            b[0][diagNum(r, c)].emplace_back(min(r, c), sqr(p));
            b[1][diagNum(n - r + 1, c)].emplace_back(min(n - r + 1, c), sqr(p));
        }

        int ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= 2 * n + 10; j++) {
                sort(all(b[i][j]));

                ans = max(ans, DP(b[i][j]));
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
