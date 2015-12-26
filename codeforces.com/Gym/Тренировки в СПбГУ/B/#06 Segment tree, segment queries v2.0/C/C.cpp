#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1001000;
const int OFFSET = 500100;

class SegmentTree {
private:
    int flag[4 * MAXN];
    int t[4 * MAXN];

    void push(int v, int l, int r) {
        if (flag[v] == -1) {
            return;
        }

        if (l != r) {
            flag[2 * v] = flag[v];
            flag[2 * v + 1] = flag[v];
        }

        t[v] = (r - l + 1) * flag[v];
        flag[v] = -1;
    }

    void set(int v, int l, int r, int ql, int qr, int val) {
        push(v, l, r);

        if (l > qr || ql > r) {
            return;
        }

        if (ql <= l && r <= qr) {
            flag[v] = val;
            push(v, l, r);
            return;
        }

        int mid = (l + r) / 2;
        set(2 * v, l, mid, ql, qr, val);
        set(2 * v + 1, mid + 1, r, ql, qr, val);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    int sum(int v, int l, int r, int ql, int qr) {
        push(v, l, r);

        if (l > qr || ql > r) {
            return 0;
        }

        if (ql <= l && r <= qr) {
            return t[v];
        }

        int mid = (l + r) / 2;
        return sum(2 * v, l, mid, ql, qr) + sum(2 * v + 1, mid + 1, r, ql, qr);
    }

public:
    void update(int pos, int val) {
        set(1, 0, MAXN - 1, pos, pos, val);
    }

    void update(int l, int r, int val) {
        set(1, 0, MAXN - 1, l, r, val);
    }

    int get() const {
        return t[1];
    }

    int get(int pos) {
        return sum(1, 0, MAXN - 1, pos, pos);
    }
};

int n;
char c;
int x, len;
SegmentTree treeA, treeB;

int main() {
    freopen("painter.in", "r", stdin);
    freopen("painter.out", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%c %d %d\n", &c, &x, &len);

        x += OFFSET;
        int l = x, r = x + len - 1;

        int color = 0;
        if (c == 'B') {
            color = 1;
        }

        treeA.update(l, r, color);
        
        int val1 = treeA.get(l - 1) ^ treeA.get(l);
        treeB.update(l - 1, val1);

        int val2 = treeA.get(r) ^ treeA.get(r + 1);
        treeB.update(r, val2);

        treeB.update(l, r - 1, 0);

        printf("%d %d\n", treeB.get() / 2, treeA.get());
    }

    return 0;
}
