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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int k;
set <pair <int, int> > Set;

void add_edge(int a, int b) {
    Set.insert(make_pair(a + 1, b + 1));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &k);

    if (k % 2 == 0) {
        puts("NO");
        return 0;
    }

    for (int i = 0; i <= k; i++) {
        for (int j = i + 1; j <= k; j++) {
            if (i != 0 || j != 1) {
                for (int q = 0; q < k - 1; q++) {
                    add_edge(i + (k + 1) * q, j + (k + 1) * q);
                }
            }
        }
    }

    int node1 = (k - 1) * (k + 1);
    int node2 = (k - 1) * (k + 1) + 1;
    int n = (k - 1) * (k + 1) + 2;

    for (int i = 0; i < (k - 1) / 2; i++) {
        add_edge(node1, (k + 1) * i);
        add_edge(node1, 1 + (k + 1) * i);
    }

    for (int i = (k - 1) / 2; i < k - 1; i++) {
        add_edge(node2, (k + 1) * i);
        add_edge(node2, (k + 1) * i + 1);
    }

    add_edge(node1, node2);

    int m = Set.size();

    puts("YES");
    printf("%d %d\n", n, m);

    for (set <pair <int, int> >::iterator it = Set.begin(); it != Set.end(); it++) {
        printf("%d %d\n", it->first, it->second);
    }

    return 0;
}
