#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Tree {
    int key, y;
    int nmb;

    Tree * l, * r;

    Tree() : l(NULL), r(NULL) {}

    Tree(int x, int y, int nmb) : key(x), y(y), nmb(nmb), l(NULL), r(NULL) {}
};

typedef Tree* PTree;

const int maxn = 50050;

int a[maxn], b[maxn], c[maxn];

void split(PTree t, int key, PTree &l, PTree &r) {
    if (!t) {
        l = r = NULL;
        return;
    }

    if (key < t -> key) {
        split(t -> l, key, l, t -> l);
        r = t;
    } else {
        split(t -> r, key, t -> r, r);
        l = t;
    }   
}

void insert(PTree &t, PTree it) {
    if (!t) {
        t = it;
        return;
    }
    
    if (it -> y < t -> y) {
        split(t, it -> key, it -> l, it -> r);
        t = it;
    } else {
        if (it -> key < t -> key)
            insert(t -> l, it);
        else
            insert(t -> r, it);
    }
}

void get_ans(PTree t, int pr = 0) {
    if (!t)
        return;
    
    int num = t -> nmb;
    
    a[num - 1] = pr;
    b[num - 1] = (t -> l) ? (t -> l -> nmb) : 0;
    c[num - 1] = (t -> r) ? (t -> r -> nmb) : 0;

    get_ans(t -> l, t -> nmb);
    get_ans(t -> r, t -> nmb);  
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    scanf("%d", &n);

    int x, y;

    PTree t = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        
        PTree it = new Tree(x, y, i + 1);
        
        insert(t, it);
    }


    puts("YES");

    get_ans(t);

    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", a[i], b[i], c[i]);

    return 0;
}
