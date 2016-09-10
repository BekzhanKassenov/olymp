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

int n;
int x[MAXN], p[MAXN];
int parent[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &p[i]);
    }

    vector <int> order;
    for (int i = 1; i <= n; i++) {
        order.push_back(i);
    }

    auto compareP = [](int a, int b) {
        return p[a] > p[b];
    };

    auto compareX = [](int a, int b) {
        return x[a] < x[b];
    };

    sort(all(order), compareP);

    parent[order[0]] = -1;
    set <int, decltype(compareX)> parents(compareX);
    parents.insert(order[0]);

    for (int i = 1; i < n; i++) {
        int v = order[i];

        auto it = parents.upper_bound(v);
        int ans = INF;

        if (it != parents.end()) {
            ans = *it;
        }

        if (it != parents.begin()) {
            it--;
            if (ans == INF || abs(x[v] - x[ans]) > abs(x[v] - x[*it])
            || (abs(x[v] - x[ans]) == abs(x[v] - x[*it]) && p[ans] < p[*it])) {
                ans = *it;
            }
        }

        parent[v] = ans;
        parents.insert(v);
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", parent[i]);
    }

    return 0;
}
