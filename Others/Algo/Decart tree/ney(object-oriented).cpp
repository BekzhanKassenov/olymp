#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

class CartesianTree {
public:
    CartesianTree(int t[], size_t size) : size(size) {
        root = NULL;
        srand(time(NULL));
        
        for (size_t i = 0; i < size; i++) {
            root = merge(root, new Node(t[i]));
        }
    }
    
    void reverse(int l, int r) {
        pNode t1, t2, t3;
        split(root, t1, t2, l);
        split(t2, t2, t3, r - l + 1);
        
        t2 -> rev ^= true;
        
        root = merge(merge(t1, t2), t3);
    }
    
    int get_min(int l, int r) {
        pNode t1, t2, t3;
        split(root, t1, t2, l);
        split(t2, t2, t3, r - l + 1);
        
        int res = node_min(t2);
        
        root = merge(merge(t1, t2), t3);
        
        return res;
    }

private:
    struct Node {
        int val, prior;
        int mn, sz;
        bool rev;
        Node *l, *r;
        
        Node() { } 
        
        Node(int val) : val(val), prior((rand() << 16) ^ rand()), mn(val), sz(1), rev(false), l(NULL), r(NULL) { }
    };
    
    typedef Node* pNode;
    
    inline void push(pNode v) {
        if (v && v -> rev) {
            if (v -> l)
                v -> l -> rev ^= true;
                
            if (v -> r)
                v -> r -> rev ^= true;
                
            swap(v -> l, v -> r);
            v -> rev = false;
        }
    }
    
    inline int node_size(pNode v) {
        return (v ? v -> sz : 0);
    }
    
    inline int node_min(pNode v) {
        return (v ? v -> mn : INF);
    }
    
    inline void update(pNode v) {
        if (v == NULL)
            return;
            
        v -> mn = min(node_min(v -> l), node_min(v -> r));
        v -> mn = min(v -> mn, v -> val);
        v -> sz = node_size(v -> l) + node_size(v -> r) + 1;
    }
    
    void split(pNode v, pNode& l, pNode& r, int key, int add = 0) {
        if (v == NULL) {
            l = r = NULL;
            return;
        }
        
        push(v);
        int pos = add + node_size(v -> l);
        
        if (pos >= key) {
            split(v -> l, l, v -> l, key, add);
            r = v;
        } else {
            split(v -> r, v -> r, r, key, pos + 1);
            l = v;
        }
        
        update(v);
    }
    
    pNode merge(pNode l, pNode r) {
        update(l);
        update(r);
        push(l);
        push(r);
        
        if (l == NULL || r == NULL)
            return (l ? l : r);
            
        if (l -> prior > r -> prior) {
            l -> r = merge(l -> r, r);
            update(l);
            return l;
        }
        
        r -> l = merge(l, r -> l);
        
        update(r);
        return r;
    }
    
    pNode root;
    size_t size;
};

const int maxn = 100010;
int a[maxn], n, m, l, r, t;

int read_int() {
    char c;
    
    do {
        c = getc(stdin);
    } while (c < '0' || c > '9');
    
    int res = 0;
    
    do {
        res = res * 10 + c - '0';
        c = getc(stdin);
    } while (c >= '0' && c <= '9');
    
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    n = read_int();
    m = read_int();
    
    for (int i = 0; i < n; i++)
        a[i] = read_int();
        
    CartesianTree tree(a, n);
    
    for (int i = 0; i < m; i++) {
        t = read_int();
        l = read_int();
        r = read_int();
        
        l--, r--;
        
        if (t == 1)
            tree.reverse(l, r);
        else
            printf("%d\n", tree.get_min(l, r));
    }
    
    return 0;
}