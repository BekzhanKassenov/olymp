#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Node* PNode;

struct Node {
    int key, prior;
    
    PNode l, r;

    Node() : key(0), prior(0), l(NULL), r(NULL) {}

    Node(int key) : key(key), prior((rand() << 16) + rand()), l(NULL), r(NULL) {}
};     

void split(PNode t, PNode& l, PNode& r, int key) {
    if (!t) {
        l = r = NULL;
        return;
    }

    if (t -> key > key) {
        split(t -> l, l, t -> l, key);
        r = t;
    } else {
        split(t -> r, t -> r, r, key);
        l = t;
    }
}

PNode merge(PNode l, PNode r) {
    if (!l || !r)
        return l ? l : r;

    if (l -> prior > r -> prior)
        return merge(l -> r, r);

    return merge(l, r -> l);
}

PNode found(PNode t, int val) {
    if (!t || t -> key == val)
        return t;

    if (t -> key > val)
        return found(t -> l, val);

    return found(t -> r, val);  
}

PNode lower_bound(PNode& t, int val) {
    if (!t || t -> key == val)
        return t;

    if (t -> key < val)
        return lower_bound(t -> r, val);

    PNode tmp = lower_bound(t -> l, val);

    return (tmp ? tmp : t);
}

void insert(PNode& t, PNode tmp) {
    if (!t) {
        t = tmp;
        return;
    }

    if (tmp -> prior > t -> prior) {
        split(t, tmp -> l, tmp -> r, tmp -> key);
        t = tmp;
        return;
    }

    if (tmp -> key < t -> key)
        insert(t -> l, tmp);
    else
        insert(t -> r, tmp);    
}

void output(PNode t) {
    if (!t)
        return;

    output(t -> l);

    cerr << t -> key << ' ';

    output(t -> r); 
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    int x;
    char c;

    bool flag = false;

    PNode root = NULL;

    int ans = -1;

    for (int i = 0; i < n; i++) {
        cin >> c >> x;

        if (c == '?') {
            PNode tmp = lower_bound(root, x);

            ans = tmp ? tmp -> key : -1;

            cout << ans << endl;

            flag = true;
        }

        if (c == '+') {
            PNode tmp = new Node(flag ? ((ans + x) % 1000000000) : x);

            if (!found(root, tmp -> key))
                insert(root, tmp);

            flag = false;
        }
    }

    return 0;
}
