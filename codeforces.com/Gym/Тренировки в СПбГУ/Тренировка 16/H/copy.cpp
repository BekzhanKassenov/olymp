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

pNode find(const pNode v, int pos, int add = 0) {
    if (v == NULL) {
        return NULL;
    }

    int key = get_size(v->left) + add + 1;
    
    //printf("%p %d\n", v, key);

    if (key == pos) {
        return v;
    }

    if (pos < key) {
        return find(v->left, pos, add);
    }

    return find(v->right, pos, key);
}

pNode insert(pNode root, int pos, int val) {
    pNode temp1, temp2;
    split(root, temp1, temp2, pos);
    pNode temp = new Node(val);
    root = merge(temp1, temp);
    root = merge(root, temp2);
    return root;
}

void print(pNode v, int add = 0) {
    if (v == NULL) {
        return;
    }
    
    if (v->left) {
        printf("left:  %p ---> %p\n", v, v->left);
    }
    
    if (v->right) {
        printf("right: %p ---> %p\n", v, v->right);
    }

    print(v->left, add);
    int key = add + get_size(v->left) + 1;
    printf("%p %d %d\n", v, key, v->key);
    print(v->right, key);
}

vector <int> result;
void print_ans(pNode v) {
    if (v == NULL) {
        return;
    }

    print_ans(v->left);
    result.push_back(v->key);
    print_ans(v->right);
}

pNode root;
int n, m;
int l[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &l[i]);
    }

    for (int i = 0; i <= n + m; i++) {
        pNode temp = new Node();
        root = merge(root, temp);
    }

    //print(root);
    //puts("");

    for (int i = 1; i <= n; i++) {
        pNode pos = find(root, l[i]);
        assert(pos != NULL);

        if (pos->key != 0) {
            root = insert(root, l[i], i);
        } else {
            pos->key = i;
        }
    }

    print_ans(root);
    while (!result.empty() && result.back() == 0) {
        result.pop_back();
    }

    printf("%d\n", result.size());
    for (size_t i = 0; i < result.size(); i++) {
        printf("%d%c", result[i], " \n"[i + 1 == result.size()]);
    }
    return 0;
}
