#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

typedef struct Node* PNode;
typedef long long ll;

struct Node {
    int key, prior, cnt;

    ll sum;

    PNode l, r;

    Node() {}

    Node(int val) : key(val), prior((rand() << 16) + rand()), cnt(1), sum((ll)val), l(NULL), r(NULL) { } 
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
        t -> sum = sum(t -> l) + sum(t -> r) + t -> key;
    }
}

void get(int l, int r, int& ans_l, int& ans_r, int md) {
    ans_l = l, ans_r = r;

    if ((ans_l & 1) != md)
        ans_l++;

    if ((ans_r & 1) != md)
        ans_r--;

    ans_l >>= 1;
    ans_r >>= 1;
}

void split(PNode t, PNode& l, PNode& r, int key, int add = 0) {
    if (!t) {
        r = l = NULL;
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
    upd(l);
    upd(r);
}

PNode merge(PNode l, PNode r) {
    if (!l || !r)
        return l ? l : r;

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

ll sum(PNode& t, int l, int r) {
    PNode t1, t2, t3;

    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);

    ll ans = sum(t2);

    t = merge(t1, t2);
    t = merge(t, t3);

    return ans;
}

ll sum(PNode& t1, PNode& t2, int l, int r) {
    int l1, r1;

    ll ans = 0;
    
    get(l, r, l1, r1, 0);
    
    if (l1 <= r1 && l1 >= 0)
        ans = sum(t1, l1, r1);

    get(l, r, l1, r1, 1);

    if (l1 <= r1 && l1 >= 0)
        ans += sum(t2, l1, r1);
    
    return ans;
}

void swap(PNode& t1, PNode& t2, int l, int r) {
    int l1, r1, l2, r2;

    get(l, r, l1, r1, 0);
    get(l, r, l2, r2, 1);

    PNode t11, t12, t13;
    PNode t21, t22, t23;

    split(t1, t11, t12, l1);
    split(t12, t12, t13, r1 - l1 + 1);

    split(t2, t21, t22, l2);
    split(t22, t22, t23, r2 - l2 + 1);

    t1 = merge(t11, t22);
    t1 = merge(t1, t13);

    t2 = merge(t21, t12);
    t2 = merge(t2, t23);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;

    srand(time(NULL));

    int cnt = 0;

    while (scanf("%d%d", &n, &m) == 2 && n > 0 && m > 0) {
        cnt++;
        PNode root_even = NULL, root_odd = NULL;

        for (int i = 0; i < n; i++) {
            int x;

            scanf("%d", &x);

            PNode tmp = new Node(x);

            if (i & 1) 
                root_odd = merge(root_odd, tmp);
            else
                root_even = merge(root_even, tmp);
        }

        int t, l, r;

        cout << "Swapper " << cnt << ":\n";
    
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &t, &l, &r);

            if (t == 1)
                swap(root_even, root_odd, l - 1, r - 1);
            else 
                printf("%lld\n", sum(root_even, root_odd, l - 1, r - 1));
        }

        puts("");
    }
    
    puts("");
    return 0;   
}
