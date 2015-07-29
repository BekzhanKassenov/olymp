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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int from, to;
    bool direction;

    void read() {
        scanf("%d%d", &from, &to);
        direction = false;
    }

    void print() {
        if (direction) {
            printf("%d %d\n", from, to);
        } else {
            printf("%d %d\n", to. from);
        }
    }
};

int n, m, x, y;
vector <int> g[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);

    }
    
    return 0;
}
