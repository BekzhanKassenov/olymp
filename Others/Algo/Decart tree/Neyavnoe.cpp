#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define INF (int)2e9

typedef struct Tree* PTree;

struct Tree {
    int prior, key;
    int cnt, min_val;
    bool rev;
    PTree l, r;

    Tree() : prior(0), key(0), cnt(0), min_val(0), rev(false), l(NULL), r(NULL) {}

    Tree(int key) : prior((rand() << 16) + rand()), key(key), cnt(1), min_val(key), rev(false), l(NULL), r(NULL) {} 
};

void output(PTree t) {
    if (!t)
        return;

    output(t -> l);

    cout << t -> key << endl;

    output(t -> r);
}

int cnt(PTree t) {
    return (t ? t -> cnt : 0);
}

int min(PTree t) {
    return (t ? t -> min_val : INF);
}

void upd(PTree t) {
    if (t) {
        t -> min_val = min(min(min(t -> l), min(t -> r)), t -> key);
        t -> cnt = cnt(t -> l) + cnt(t -> r) + 1;
    }
}

void push(PTree t) {
    if (t && t -> rev) {
        if (t -> l)
            t -> l -> rev ^= 1;

        if (t -> r)
            t -> r -> rev ^= 1;

        t -> rev = false;
        swap(t -> l, t -> r);
    }
}

void split(PTree t, PTree& l, PTree& r, int key, int c = 0) {
    if (!t) {
        l = r = NULL;
        return;
    }

    push(t);

    int cur = c + cnt(t -> l);

    if (key <= cur) {
        split(t -> l, l, t -> l, key, c);
        r = t;
    } else {
        split(t -> r, t -> r, r, key, cur + 1);
        l = t;
    }

    upd(t);
}   

void merge(PTree& t, PTree l, PTree r) {
    push(l);
    push(r);

    if (!l || !r) {
        t = l ? l : r;
        return;
    }

    if (l -> prior > r -> prior) {
        merge(l -> r, l -> r, r);
        t = l;
    } else {
        merge(r -> l, l, r -> l);
        t = r;
    }

    upd(t);
}   

void insert(PTree& t, int pos, int val) {
    PTree t1, t2;

    split(t, t1, t2, pos);

    PTree tmp = new Tree(val);

    merge(t, t1, tmp);
    merge(t, t, t2);
}

void reverse(PTree& t, int l, int r) {
    PTree t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);

    t2 -> rev ^= 1;

    merge(t, t1, t2);
    merge(t, t, t3);
}

int get_ans(PTree& t, int l, int r) {
    PTree t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);

    int ans = min(t2);

    merge(t, t1, t2);
    merge(t, t, t3);

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;

    cin >> n >> m;

    int x;

    PTree t = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;

        insert(t, i, x);
    }

    for (int i = 0; i < m; i++) {
        int tp, l, r;

        cin >> tp >> l >> r;

        l--, r--;

        if (tp == 1) 
            reverse(t, l, r);
        else
            cout << get_ans(t, l, r) << endl;
    }

    return 0;
}