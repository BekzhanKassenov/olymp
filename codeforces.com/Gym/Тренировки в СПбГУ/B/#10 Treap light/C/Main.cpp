/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "next"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node;

typedef Node* pNode;

struct Node {
    int num, prior;
    pNode left, right;

    Node(int num) :
        num(num),
        prior((rand() << 16) ^ rand()),
        left(NULL),
        right(NULL) { }
};

void split(pNode v, pNode& l, pNode& r, int key) {
    if (v == NULL) {
        l = r = NULL;
        return;
    }

    if (v->num <= key) {
        split(v->right, v->right, r, key);
        l = v;
    } else {
        split(v->left, l, v->left, key);
        r = v;
    }
}

void insert(pNode& v, pNode it) {
    if (v == NULL) {
        v = it;
        return;
    }

    if (it->prior > v->prior) {
        split(v, it->left, it->right, it->num);
        v = it;
    } else {
        if (it->num < v->num) {
            insert(v->left, it);
        } else if (it->num > v->num) {
            insert(v->right, it);
        }
    }
}

pNode lower_bound(pNode v, int key) {
    if (v == NULL) {
        return NULL;
    }

    if (v->num == key) {
        return v;
    }

    if (key < v->num) {
        pNode temp = lower_bound(v->left, key);
        if (temp == NULL) {
            return v;
        }

        return temp;
    }

    return lower_bound(v->right, key);
}

pNode root = NULL;
int n, x, last = -2;
char c;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("\n%c %d", &c, &x);

        if (c == '+') {
            if (last != -2) {
                x += last;
                x %= MOD;
                x += MOD;
                x %= MOD;
                last = -2;
            }   

            pNode it = new Node(x);
            insert(root, it);
        } else {
            pNode res = lower_bound(root, x);
            if (res == NULL) {
                puts("-1");
                last = -1;
            } else {
                printf("%d\n", res->num);
                last = res->num;
            }
        }
    }

    return 0;
}
