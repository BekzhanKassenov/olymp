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
typedef pair <int, int> Segment;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, a, m, x;

bool check(const Segment& seg) {
    if (seg.second < seg.first) {
        return false;
    }

    return seg.second - seg.first + 1 >= a;
}

vector <Segment> split(const Segment& seg, int pos) {
    Segment seg1 = Segment(seg.first, pos - 1);
    Segment seg2 = Segment(pos + 1, seg.second);

    vector <Segment> result;

    if (check(seg1)) {
        result.emplace_back(seg1);
    }

    if (check(seg2)) {
        result.emplace_back(seg2);
    }

    return result;
}

struct Compare {
    bool operator () (const Segment& lhs, const Segment& rhs) const {
        return lhs.first < rhs.first;
    }
};

int size(const Segment& seg) {
    int len = seg.second - seg.first + 1;

    int ans = len / (a + 1);

    if (len % (a + 1) == a) {
        ans++;
    }

    return ans;
}

set <Segment, Compare> Set;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &k, &a);

    Set.insert(Segment(1, n));
    int cnt = size(Segment(1, n));

    scanf("%d", &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d", &x);

        auto it = Set.upper_bound(make_pair(x, 0));

        if (it == Set.begin()) {
            continue;
        }

        it--;

        if (it->first <= x && x <= it->second) {
            Segment seg = *it;
            Set.erase(it);
            cnt -= size(seg);

            vector <Segment> vec(split(seg, x));

            for (auto segm: vec) {
                Set.insert(segm);
                cnt += size(segm);
            }

            if (cnt < k) {
                printf("%d\n", i);
                return 0;
            }
        }
    }

    puts("-1");

    return 0;
}
