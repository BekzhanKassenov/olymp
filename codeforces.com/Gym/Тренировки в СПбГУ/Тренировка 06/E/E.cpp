#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 70010;
const int OFFSET = 30010;

class SegmentTree {
private:
    int t[4 * MAXN];
    int flag[4 * MAXN];
    int width;

    void push(int v, int l, int r) {
        t[v] += flag[v];

        if (l != r) {
            flag[2 * v] += flag[v];
            flag[2 * v + 1] += flag[v];
        }

        flag[v] = 0;
    }

    void add(int v, int l, int r, int ql, int qr, int val) {
        push(v, l, r);

        if (l > qr || ql > r) {
            return;
        }

        if (ql <= l && r <= qr) {
            flag[v] += val;
            push(v, l, r);
            return;
        }

        int mid = (l + r) / 2;
        add(2 * v,     l,       mid, ql, qr, val);
        add(2 * v + 1, mid + 1,   r, ql, qr, val);

        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

public:
    SegmentTree() { 
        memset(t, 0, sizeof t);
        memset(flag, 0, sizeof flag);
    }

    void update(int pos, int val) {
        int l = max(0, pos - width);
        int r = min(pos, MAXN - 1 - width);

        add(1, 0, MAXN - 1, l, r, val);
    }

    int get() const {
        return t[1];
    }

    void setWidth(int w) {
        this->width = w;
    }
};

int s, w, n;
vector <int> a[MAXN];
SegmentTree tree;

int main() {
    freopen("mine.in", "r", stdin);
    freopen("mine.out", "w", stdout);

    scanf("%d%d", &s, &w);
    scanf("%d", &n);

    tree.setWidth(w);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        x += OFFSET;
        y += OFFSET;

        a[x].push_back(y);
    }

    for (int i = 0; i <= s; i++) {
        for (int x: a[i]) {
            tree.update(x, 1);
        }
    }

    int ans = tree.get();

    for (int i = s + 1; i < MAXN; i++) {
        for (int x: a[i - s - 1]) {
            tree.update(x, -1);
        }

        for (int x: a[i]) {
            tree.update(x, 1);
        }

        ans = max(ans, tree.get());
    }
    
    printf("%d\n", ans);

    return 0;
}
