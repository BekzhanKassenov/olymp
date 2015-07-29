/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 135 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int get_prior() {
    static vector <int> numbers(2 * MAXN);
    static int last_position = 0;
    static bool initialized;

    if (!initialized) {
        srand(time(NULL));
        for (size_t i = 0; i < numbers.size(); i++) {
            numbers[i] = i;
        }

        random_shuffle(all(numbers));
        initialized = true;
    }

    return numbers[last_position++];
}

struct Node {
    int key, prior;
    int size;
    Node *left, *right;

    Node() : key(0), prior(get_prior()), size(1), left(NULL), right(NULL) { }

    Node(int key) : key(key), prior(get_prior()), size(1), left(NULL), right(NULL) { }
};

typedef Node* pNode;

int get_size(const pNode v) {
    if (v == NULL) {
        return 0;
    }

    return v->size;
}

void update_size(const pNode v) {
    if (v != NULL) {
        v->size = get_size(v->left) + get_size(v->right) + 1;
    }
}

void split(const pNode v, pNode& l, pNode& r, int key, int add = 0) {
    if (v == NULL) {
        l = r = NULL;
        return;
    }

    int vkey = get_size(v->left) + add + 1;
    if (key <= vkey) {
        split(v->left, l, v->left, key, add);
        r = v;
    } else {
        split(v->right, v->right, r, key, vkey);
        l = v;
    }

    update_size(l);
    update_size(r);
}

pNode merge(const pNode l, const pNode r) {
    if (l == NULL || r == NULL) {
        return l == NULL ? r : l;
    }

    pNode ans = NULL;
    if (l->prior > r->prior) {
        l->right = merge(l->right, r);
        ans = l;
    } else {
        r->left = merge(l, r->left);
        ans = r;
    }

    update_size(ans);
    return ans;
}

pNode insert(pNode root, int pos, int val) {
    pNode temp1, temp2;
    split(root, temp1, temp2, pos);
    pNode temp = new Node(val);
    root = merge(temp1, temp);
    root = merge(root, temp2);
    return root;
}

typedef pair <pair <int, int>, pNode> > set_item;
typedef set <set_item>::iterator set_iter;

struct Compare {
    bool operator ()(const set_item& lhs, const set_item& rhs) {
        return lhs.first.first < rhs.first.first;
    }
};

set <set_item, Compare> Set;

set_iter get_iter(int pos) {
    set_iter result = Set.upper_bound(make_pair(make_pair(pos, 0), NULL));

    if (result == Set.begin()) {
        result = Set.end();
    } else {
        result--;
        if (!((result->first).first <= pos && pos <= (result->first).second)) {
            result = Set.end();
        }
    }

    return result;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);

        set_iter prev = get_iter(x - 1);
        set_iter curt = get_iter(x);
        set_iter next = get_iter(x + 1);
    }    
    return 0;
}
