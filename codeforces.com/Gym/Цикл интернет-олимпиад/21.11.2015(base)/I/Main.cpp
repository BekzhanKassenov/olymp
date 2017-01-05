/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "weapons"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple <int, int, int> item;

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
vector <tuple <int, int, int> > vec[2];

constexpr int first(const item& a) {
    return get<0>(a);
}

constexpr int second(const item& a) {
    return get<1>(a);
}

constexpr int idx(const item& a) {
    return get<2>(a);
}

int ans[MAXN];

int sizediff() {
    int size0 = vec[0].size();
    int size1 = vec[1].size();
    return abs(size0 - size1);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y) {
            vec[0].emplace_back(x, y, i);
        } else {
            vec[1].emplace_back(x, y, i);
        }
    }

    sort(all(vec[0]), [](const item& x, const item& y) {
        return first(x) - second(x) > first(y) - second(y);
    });

    sort(all(vec[1]), [](const item& x, const item& y) {
        return second(x) - first(x) > second(y) - first(y);
    });

    int idx1 = 0, idx2 = 1;
    if (vec[0].size() > vec[1].size()) {
        swap(idx1, idx2);
    }

    while (sizediff() > m) {
        vec[idx1].emplace_back(vec[idx2].back());
        vec[idx2].pop_back();
    }

    int sum = 0;
    for (const auto& p : vec[0]) {
        ans[idx(p)] = 0;
        sum += first(p);
    }

    for (const auto& p : vec[1]) {
        ans[idx(p)] = 1;
        sum += second(p);
    }

    printf("%d\n", sum);
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    puts("");

    return 0;
}
