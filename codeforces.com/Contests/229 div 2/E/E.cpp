#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <functional>
#include <cassert>
#include <cmath>
#include <bitset>
#include <ctime>

#define filename ""
#define sqr(a) ((a)*(a))

using namespace std;
const int MAXN = (int)4e6 + 10;

int n, m, w ;//, rr[MAXN], cc[MAXN];
long long total = 0;

struct st {
    vector< pair<long long, long long> > tree;
    st() {}
    st(int n) {
        tree.resize(4*n);
        build(1, 0, n - 1);
    }
    void build(int v, int L, int R) {
        if (L == R)
            ;//tree[v].first = a[L]; 
        else {
            int mid = L + (R - L)/2;
            build(2*v, L, mid); build(2*v + 1, mid + 1, R);
            tree[v].first = tree[2*v + 1].first + tree[2*v].first;
        }
    }
    void push(int v, int L, int R) {
        if (L > R) return;
        if (L == R) {
            tree[v].first += tree[v].second ;
            tree[v].second = 0;
        } else 
        if (tree[v].second != 0) {
            tree[2*v].second += tree[v].second;
            tree[2*v + 1].second += tree[v].second;
            tree[v].first += 1ll * (R - L + 1) * tree[v].second;
            tree[v].second = 0;
        }
    }
    long long getsum(int v, int L, int R, int l, int r) {
        if (l > r) return 0;
        push(v, L, R);
        if (L == l && R == r) {
            return tree[v].first ;
        }
        int mid = L + (R - L)/2;
        long long ret = getsum(2*v, L, mid, l, min(r, mid)) + getsum(2*v + 1, mid + 1, R, max(l, mid + 1), r);
        push(2*v, L, mid); push(2*v + 1, mid + 1, R);
        return ret;
    }
    void add(int v, int L, int R, int l, int r, long long val) {
        if (l > r) return ;
        if (L == l && R == r) {
            push(v, L, R);
            tree[v].second += val;
        }
        else {
            push(v, L, R);
            int mid = L + (R - L)/2;
            add(2*v, L, mid, l, min(r, mid), val);
            add(2*v+1, mid + 1, R, max(l, mid + 1), r, val);
            push(2*v, L, mid); push(2*v + 1, mid + 1, R);
            tree[v].first = tree[2 * v].first + tree[2 * v + 1].second;
        }
        push(v, L, R);
    }
};


int main() {
    //std::ios_base::sync_with_stdio(false);
    assert(freopen("in", "r", stdin));
    //assert(freopen(filename ".out", "w", stdout));

    scanf("%d%d%d", &n, &m, &w);
    st rows(n), cols(m);
    while ( w -- ) {
        int type = 0;
        scanf("%d", &type);
        if (type == 0) {
            int x1, x2, y1, y2, v;
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
            x1 --; x2 --; y1 --; y2 --;
            rows.add(1, 0, n - 1, x1, x2, 1LL* v * (y2 - y1 + 1));
            cols.add(1, 0, m - 1, y1, y2, 1LL * (x2 - x1 + 1) * v);
            total += 1LL * (x2 - x1 + 1) * (y2 - y1 + 1) * 1LL * v;
        } else {
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1 --; x2 --; y1 --; y2 --;
            long long inc = cols.getsum(1, 0, m - 1, y1, y2), inr = rows.getsum(1, 0, n - 1, x1, x2);
            printf("%I64d\n", -total + inc + inr);
        }
    }
    /*
    for (int i = 0 ; i < m ; i ++)
        cout << cols.getsum(1, 0, m - 1, i, i) << endl;
    for (int i = 0 ; i < n ; i ++)
        cout << rows.getsum(1, 0, n - 1, i, i) << endl;
        */


    return 0;
}