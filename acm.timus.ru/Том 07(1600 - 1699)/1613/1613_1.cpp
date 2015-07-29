#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int maxn = 100000;

vector <int> t[4 * maxn];
int a[maxn], n, m, l, r, val;

void build(int v, int l, int r) {
    if (l > r)
        return;

    if (l == r) {
        t[v].push_back(a[l]);
        return;
    }

    int m = (l + r) >> 1;

    build(v << 1, l, m);
    build((v << 1) + 1, m + 1, r);

    merge(all(t[v << 1]), all(t[(v << 1) + 1]), back_inserter(t[v]));
}

bool get_ans(int v, int l, int r, int q_l, int q_r, int val) {
    if (l > r || l > q_r || r < q_l)
        return false;

    if (l >= q_l && r <= q_r) 
        return binary_search(all(t[v]), val);

    int m = (l + r) >> 1;

    return (get_ans(v << 1, l, m, q_l, q_r, val) || get_ans((v << 1) + 1, m + 1, r, q_l, q_r, val));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    build(1, 0, n - 1);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &l, &r, &val);

        putchar(get_ans(1, 0, n - 1, l - 1, r - 1, val) ? '1' : '0');
    }

    return 0;
}
