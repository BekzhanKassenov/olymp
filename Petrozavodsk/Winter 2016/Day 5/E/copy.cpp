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
const int BSIZE = 450;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
bool eq[BSIZE][BSIZE];
int parent[MAXN];

int getParent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return parent[v] = gerParent(parent[v]);
}

void unite(int a, int b) {
    parent[getParent(a)] = getParent(b);
}

void query(int l1, int r1, int l2, int r2) {
    if (l1 == l2) {
        return;
    }

    if (l1 <= l2 && l2 <= r1) {
        int len1 = (r1 - l2 + 1);

        query(l1, l1 + len1 - 1, l2, r1);
        query(l2, r1, r1 - len1 + 1, r1);
        query(l1 + len1, l2 - 1, r1 + 1, r2 - len1);
    } else if (l2 <= l1 && l1 <= r2) {
        query(l2, r2, l1, r1);
    } else {
        //
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int x, y, l;
            scanf("%d%d%d", &x, &y, &l);

            int l1 = x;
            int r1 = x + l - 1;
            int l2 = y;
            int r2 = y + l - 1;

            query(l1, r1, l2, r2);
        }
    }
    
    return 0;
}
