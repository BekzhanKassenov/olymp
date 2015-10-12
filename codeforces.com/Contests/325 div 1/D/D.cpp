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
const int MAXN = 25;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Triple {
    int a, b, c;

    int max() const {
        return std::max(std::max(a, b), c);
    }

    tuple <int, int, int> get_diff() const {
        return tuple <int, int, int> (a - b, b - c, a - c);
    }
};

int n;
int l[MAXN], m[MAXN], w[MAXN];
vector <int> cur_mask;

map <tuple <int, int, int>, Triple> Map1;
map <tuple <int, int, int>, vector <int> > Map2;

vector <int> ans;
int anssum = -INF;

void go(int pos, const Triple& t, bool first) {
    if (pos == n / 2 && first) {
        tuple <int, int, int> tp(t.get_diff());

        if (!Map1.count(tp) || t.max() > Map1[tp].max()) {
            Map1[tp] = t;
            Map2[tp] = cur_mask;
        }

        return;
    }

    if (pos == n && !first) {
        int a, b, c;
        tie(a, b, c) = t.get_diff();

        tuple <int, int, int> tp(-a, -b, -c);

        if (Map1.count(tp)) {
            Triple other = Map1[tp];

            assert(t.a + other.a == t.b + other.b && t.b + other.b == t.c + other.c);

            if (t.a + other.a > anssum) {
                anssum = t.a + other.a;

                ans.clear();

                for (auto x: Map2[tp]) {
                    ans.push_back(x);
                }

                for (auto x: cur_mask) {
                    ans.push_back(x);
                }
            }
        }

        return;
    }

    for (int mask = 0; mask < 8; mask++) {
        if (__builtin_popcount(mask) != 2) {
            continue;
        }

        Triple triple(t);
        if (mask & 1) {
            triple.a += l[pos];
        }

        if (mask & 2) {
            triple.b += m[pos];
        }

        if (mask & 4) {
            triple.c += w[pos];
        }

        cur_mask.push_back(mask);
        go(pos + 1, triple, first);
        cur_mask.pop_back();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &l[i], &m[i], &w[i]);
    }

    Triple empty;
    empty.a = empty.b = empty.c = 0;

    go(0, empty, true);
    go(n / 2, empty, false);

    if (ans.empty()) {
        puts("Impossible");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int mask = ans[i];

        if (mask & 1) {
            putchar('L');
        }   

        if (mask & 2) {
            putchar('M');
        }

        if (mask & 4) {
            putchar('W');
        }

        putchar('\n');
    }

    return 0;
}
