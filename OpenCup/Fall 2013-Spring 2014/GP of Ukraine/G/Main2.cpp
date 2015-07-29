/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

#define left asdasdas
#define right asdasdasdasd

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int left_a[maxn], left_b[maxn], left_c[maxn];
int right_a[maxn], right_b[maxn], right_c[maxn];
int last[3], n;

struct Queue {
    Queue() : root(NULL) { 
        srand(time(NULL));
    }   

    struct Node {
        int _left, _right, mx;
        
        Node *l, *r;
        
        Node() { }
        
        Node(int _left, int _right) : _left(_left), _right(_right), mx(_right), l(NULL), r(NULL) { }
    };
    
    Node* merge(Node* l, Node* r) {
        if (!l || !r)
            return l ? l : r;
            
        cout << l -> _left << ' ' << r -> _left << endl;
            
        if (l -> _left > r -> _left) {
            swap(l, r);
        }
        
        if (rand() & 1)
            swap(l -> l, l -> r);
            
        if (!l -> l || !l -> r)
            (!(l -> l)) ? (l -> l) : (l -> r) = r;
        else
            l -> r = merge(l -> r, r);
            
        upd_mx(l);
        upd_mx(r);
        
        return l;
    }
    
    void add(int l, int r) {
        Node *temp = new Node(l, r);
        
        root = merge(root, temp);
    }
    
    void pop() {
        root = merge(root -> l, root -> r);
    }
    
    bool empty() {
        return root;
    }
    
    int get_mx(Node* v) {
        return (v ? 0 : v -> mx);
    }
    
    void upd_mx(Node* v) {
        if (v)
            v -> mx = max(v -> _right, max(get_mx(v -> l), get_mx(v -> r)));
    }
    
    Node* root;
};

Queue q;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    string s, t;
    
    cin >> s >> t;
    
    n = s.size();
    
    last[0] = last[1] = last[2] = -1;
    
    for (int i = n - 1; i >= 0 && last[0] == -1 && last[1] == -1 && last[2] == -1; i--) {
        if (last[s[i] - 'a'] == -1) {
            last[s[i] - 'a'] = n - i - 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] =  -1;
                 
        for (int j = 0; j < 3; j++)
            last[j]++;
            
        left_a[i] = last[0];
        left_b[i] = last[1];
        left_c[i] = last[2];
    }

    last[0] = last[1] = last[2] = -1;
    
    for (int i = 0; i < n && last[0] == -1 && last[1] == -1 && last[2] == -1; i++) {
        if (last[s[i] - 'a'] == -1) {
            last[s[i] - 'a'] = i;
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        last[s[i] - 'a'] = -1;
        
        for (int j = 0; j < 3; j++)
            last[j]++;
            
        right_a[i] = last[0];
        right_b[i] = last[1];
        right_c[i] = last[2];
    }
    
    for (int i = 0; i < n; i++) {
        q.add(left_a[i], right_a[i]);
        q.add(left_b[i], right_b[i]);
        q.add(left_c[i], right_c[i]);
    }
    
    int ans = INF;
    
    int l = 0;
    
    while (!q.empty()) {
        while (!q.empty() && q.root -> _left < l)
            q.pop();
            
        ans = min(ans, min(l, q.get_mx(q.root)) * 2 + max(l, q.get_mx(q.root)));
    }
    
    cout << ans;
    
    return 0;
}
