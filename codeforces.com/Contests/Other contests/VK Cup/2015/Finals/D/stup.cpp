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

int parent[MAXN];
int n;

int get_parent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return v = get_parent(parent[v]);
}

void unite(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        parent[b] = a;
    }
}

void query1(int x, int y) {
    unite(x, y);
}

void query2(int x, int y) {
    for (int i = x + 1; i <= y; i++) {
        unite(x, i);
    }
}

int query3(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);

    return x == y;
}

int q, type, x, y;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    while (q--) {
        scanf("%d%d%d", &type, &x, &y);

        x--, y--;

        if (type == 1) {
            query1(x, y);
        } else if (type == 2) {
            query2(x, y);
        } else {
            if (query3(x, y)) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    
    return 0;
}
                             