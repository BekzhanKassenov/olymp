#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Node* PNode;
typedef long long ll;

struct Node {
    int key, prior, cnt;

    ll sum;

    PNode l, r;

    Node() {}

    Node(int key): key(key), prior((rand() << 16) + rand()), cnt(1), sum((ll)key), l(NULL), r(NULL) {};
};

int cnt(PNode t) {
    return (t ? t -> cnt : 0);
}

ll sum(PNode t) {
    return (t ? t -> sum : 0);
}

void upd(PNode t) {
    if (t) {
        t -> cnt = cnt(t -> l) + cnt(t -> r) + 1;
        t -> sum = sum(t -> l) + sum(t -> r) + t -> cnt;
    }
}

void clear(PNode t) {
    if (!t)
        return;

    clear(t -> l);
    clear(t -> r);

    delete t;
}

void split(PNode t, PNode &l, PNode &r, int key, int add = 0) {
    if (!t) {
        l = r = NULL;
        return;
    }

    int cur = add + cnt(t -> l);

    if (key <= cur) {
        split(t -> l, l, t -> l, key, add);
        r = t;
    } else {
        split(t -> r, t -> r, r, key, cur + 1);
        l = t;
    }

    upd(t);
}

PNode merge(PNode l, PNode r) {
    if (!l || !r)
        return (l ? l : r);

    PNode ans;

    if (l -> prior > r -> prior) {
        l -> r = merge(l -> r, r);
        ans = l;
    } else {
        r -> l = merge(l, r -> l);
        ans = r;
    }

    upd(ans);

    return ans;
}

void get(int &l, int &r, int mod) {
    if ((l & 1) != mod)
        l++;

    if ((r & 1) != mod)
        r--;

    l >>= 1;
    r >>= 1;
}

ll sum(PNode &t, int l, int r) {
    if (l <= r) {
        PNode t1, t2, t3;
        split(t, t1, t2, l);
        split(t2, t2, t3, r - l + 1);
        ll ans = sum(t2);

        t = merge(t1, t2);
        t = merge(t, t3);
        return ans;
    }

    return 0;
}

ll sum(PNode &even, PNode &odd, int l, int r) {
    int l1 = l, r1 = r;
    get(l1, r1, 0);

    ll ans = sum(even, l1, r1);

    l1 = l, r1 = r;

    get(l1, r1, 1);

    ans += sum(odd, l1, r1);
}

void swap(PNode &even, PNode &odd, int l, int r) {
    PNode t1_1, t1_2, t1_3;
    PNode t2_1, t2_2, t2_3;

    int l1 = l, r1 = r, l2 = l, r2 = r;

    get(l1, r1, 0);
    get(l2, r2, 1);

    split(even, t1_1, t1_2, l1);
    split(t1_2, t1_2, t1_3, r1 - l1 + 1);

    split(odd, t2_1, t2_2, l2);
    split(t2_2, t2_2, t2_3, r2 - l2 + 1);

    even = merge(t1_1, t2_2);
    even = merge(even, t1_3);

    odd = merge(t2_1, t1_2);
    odd = merge(odd, t2_3);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;

    int cnt = 0;

    while (scanf("%d%d", &n, &m) == 2 && n > 0) {
        PNode odd = NULL, even = NULL;
        cnt++;
        printf("Swapper %d:\n", cnt);
        int x;

        for (int i = 0; i < n; i++) {
            scanf("%d", &x);

            PNode tmp = new Node(x);

            if (i & 1)
                odd = merge(odd, tmp);
            else
                even = merge(even, tmp);
        }

        int t, l, r;

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &t, &l, &r);
            l--, r--;

            if (t == 1)
                swap(even, odd, l, r);
            else {
                printf("%lld\n", sum(even, odd, l, r));
                cerr << sum(even, odd, l, r) << endl;
            }
        }
        clear(even);
        clear(odd);
    }

    return 0;
}
