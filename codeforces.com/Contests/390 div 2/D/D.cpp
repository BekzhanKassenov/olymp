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
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Pair {
    int first, second;
    int idx;

    bool operator < (const Pair& other) const {
        if (first != other.first) {
            return first < other.first;
        }

        return second < other.second;
    }
};

int n, k;
Pair a[MAXN];
int tree[3 * MAXN];

vector <int> nums;
int get_pos(int k) {
    return lower_bound(all(nums), k) - nums.begin();
}

void add(long long pos, int delta) {
    for (int i = pos; i < (int)nums.size(); i |= i + 1) {
        tree[i] += delta;
    }
}

int sum(long long pos) {
    int ans = 0;
    for (long long i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        ans += tree[i];
    }

    return ans;
}

int sum(int l, int r) {
    int ans = sum(r);
    if (l > 0) {
        ans -= sum(l - 1);
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
        a[i].idx = i + 1;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        nums.push_back(a[i].first);
        nums.push_back(a[i].second);
    }

    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());

    bool found = false;
    int ansl = 0, ansr = 0;
    for (int i = 0; i < n; i++) {
        const auto& p = a[i];
        add(get_pos(p.second), 1);

        long long l = get_pos(p.first), r = nums.size() - 1;
        long long res = l;
        bool got = false;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (sum(mid, nums.size() - 1) >= k) {
                res = mid;
                l = mid + 1;
                got = true;
            } else {
                r = mid - 1;
            }
        }

        if (got && (!found || ansr - ansl < nums[res] - p.first)) {
            ansl = p.first;
            ansr = nums[res];
            found = true;
        }
    }
    if (found) {
        printf("%d\n", ansr - ansl + 1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            const auto& p = a[i];
            if (p.first <= ansl && p.second >= ansr) {
                printf("%d ", p.idx);
                cnt++;
                if (cnt == k) {
                    break;
                }
            }
        }
    } else {
        puts("0");
        for (int i = 1; i <= k; i++) {
            printf("%d ", i);
        }
    }
    puts("");

    return 0;
}
