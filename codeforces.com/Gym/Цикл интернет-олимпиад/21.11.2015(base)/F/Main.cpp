/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "parade"

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

enum TYPE {
    OPEN,
    CLOSE
};

int n, m;
pair <int, int> a[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }

    sort(a, a + m);
    m = unique(a, a + m) - a;

    vector <tuple <int, TYPE, int> > vec;
    for (int i = 0; i < m; i++) {
        vec.emplace_back(a[i].first, OPEN, i);
        vec.emplace_back(a[i].second, CLOSE, i);
    }

    sort(all(vec));
    multiset <int> r;
    int size = 1;
    for (const auto& event : vec) {
        if (get<1>(event) == OPEN) {
            int idx = get<2>(event);
            auto it = r.lower_bound(a[idx].second);
            if (it == r.end()) {
                size = max(size, a[idx].second - a[idx].first + 1);
            }
            r.insert(a[idx].second);
        } else {
            r.erase(r.find(get<0>(event)));
        }
    }

    printf("%d\n", size);
    for (int i = 0; i < n; i++) {
        printf("%d%c", i % size + 1, " \n"[i == n - 1]);
    }


    return 0;
}
