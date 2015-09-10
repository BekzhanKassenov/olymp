/****************************************
**          Solution by NU #2          **
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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char label[MAXN][35];

int dist(char label1[], char label2[]) {
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, abs(label1[i] - label2[i]));
    }

    return ans;
}

struct Edge {
    int from, to, cost;
    bool operator < (const Edge& e) const {
        return cost < e.cost;
    }
};

Edge e[MAXN * MAXN];
int last;
int par[MAXN];

int get(int v) {
    if (par[v] == v) {
        return v;
    }

    return par[v] = get(par[v]);
}

bool unite(int a, int b) {
    a = get(a);
    b = get(b);

    if (a != b) {
        par[a] = b;
        return true;
    }

    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(label[i]);
        par[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            e[last++] = {i, j, dist(label[i], label[j])};
        }
    }

    int ans = 0;
    sort(e, e + last);
    for (int i = 0; i < last; i++) {
        if (unite(e[i].from, e[i].to)) {
            ans = max(ans, e[i].cost);
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
