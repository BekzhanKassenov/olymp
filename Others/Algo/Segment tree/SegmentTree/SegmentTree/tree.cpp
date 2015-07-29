#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>

typedef long long i64;

using namespace std;

struct Node {
    
    Node() {
        sum = value = type = 0;
    }

    i64 sum, value;
    int type;
};

struct Tree {

    int level;
    Node *Z;
    
    /*
     * REDO
     */
    Tree(int size) {
        for (level = 1; level < size; level <<= 1);
        Z = new Node[2 * level];
    }

    void updateType(int t, int v) {
        if (v == 2) {
            if (Z[t].type == 0) Z[t].type = 2;
        } else if (v == 1) {
            Z[t].type = 1;
        } else assert(0);
    }

    void update(int t, int l, int r) {
        if (Z[t].type == 2) Z[t].sum = Z[2 * t].sum + Z[2 * t + 1].sum + (r - l + 1) * Z[t].value;
        if (Z[t].type == 1) Z[t].sum = (r - l + 1) * Z[t].value;
    }

    void push(int t, int l, int r) {
        if (l == r || Z[t].type == 0) return;
        if (Z[t].type == 2) {
            updateType(2 * t, 2);
            updateType(2 * t + 1, 2);
            Z[2 * t].value += Z[t].value;
            Z[2 * t + 1].value += Z[t].value;
        } else if (Z[t].type == 1) {
            // :TODO
        } else assert(0);
        Z[t].type = 0;
        Z[t].value = 0;
        update(2 * t, l, (l + r) >> 1);
        update(2 * t + 1, 1 + ((l + r) >> 1), r);
        update(t, l, r);
        
    }

    void add(int l, int r, int a, int b, int t, int x) {
        if (l > b || r < a) return;
        push(t, l, r);
        if (a <= l && r <= b) {
            updateType(t, 2);
            Z[t].value += x;
        } else {
            int mid = (l + r) >> 1;
            add(l, mid, a, b, t << 1, x);
            add(mid + 1, r, a, b, 1 + (t << 1), x);
        }
        push(t, l, r);
    }
    
    void add(int l, int r, int x) {
        add(level, 2 * level - 1, l + level - 1, r + level - 1, 1, x); 
    }

    i64 get(int l, int r, int a, int b, int t) {
        if (l > b || r < a) return 0;
        push(t, l, r);
        if (a <= l && r <= b) {
            return Z[t].sum;
        }
        int mid = (l + r) >> 1;
        i64 res = 0;
        res += get(l, mid, a, b, t << 1);
        res += get(mid + 1, r, a, b, 1 + (t << 1));
        push(t, l, r);
        return res;
    }

    void set(int l, int r, int x) {
    }

    i64 get(int l, int r) {
        return get(level, 2 * level - 1, l + level - 1, r + level - 1, 1);
    }

};

Tree tree(8);

int main() {
    freopen("input", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        char s[10];
        scanf("%s", s);
        int l, r, x;
        if (strcmp(s, "ADD") == 0) {
            scanf("%d%d%d", &l, &r, &x);
            tree.add(l, r, x);
        } else if (strcmp(s, "SET") == 0) {
            scanf("%d%d%d", &l, &r, &x);
            tree.set(l, r, x);
        } else if (strcmp(s, "GET") == 0) {
            scanf("%d%d", &l, &r);
            printf("%d\n", tree.get(l, r));
        } else {
            assert(0);
        }
    }

    return 0;
}