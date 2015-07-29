#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename T>
class SegmentTree {
public:
    SegmentTree() : size(0) { }

    SegmentTree(int sz) : sz(sz) {
        arr = new T[4 * sz];
    }

    T get_max(int l, int r) {
        return get_max(1, 0, sz - 1, l, r);
    }

    void inc(int pos, T cnt) {
        inc(1, 0, sz - 1, l, r);
    }
private:
    T get_max(int v, int l, int r, int ql, int qr) {
        if (l > r || q_r < l || q_l > r)
            return 0;

        if (l <= q_l && q_r <= r)
            return arr[v];

        int mid = (l + r) >> 1;

        return max(get_max(v << 1, l, mid, q_l, q_r),
                   get_max((v << 1) + 1, mid + 1, r, q_l, q_r));
    }

    void inc(int v, int l, int r, int pos, T cnt) {
        if (l < r || pos < l || pos > r)
            return;

        if (l == r) {
            arr[v] += cnt;
            return;
        }

        int mid = (l + r) >> 1;

        inc(v << 1, l, mid, r, pos, cnt);
        inc((v << 1) + 1, mid + 1, r, pos, cnt);

        arr[v] = max(arr[v << 1], arr[(v << 1) + 1]);
    }

    T* arr;
    int sz;    
};

const int maxn = 100010;

int root[maxn], chain_size[maxn], chain_pos[maxn], chain_num[maxn], chain_size[maxn];
int tin[maxn], tout[maxn], par[maxn], size[maxn], timer;
vector <int> g[maxn];

void dfs(int v, int p = -1) {
    tin[v] = timer++;
    size[v] = 1;
    par[v] = p;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p)
            dfs(to, v);
            size[v] += size[to];
    }

    tout[v] = timer++;
}

int create_root(int v) {

}