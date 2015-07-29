#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long sum(long long num) {
    return num * (num + 1) / 2;
}

struct Node {
    int l, r;
    long long sum;
    bool reversed;
    Node *left, *right;

    Node() { }

    Node(int l, int r) : l(l),
                         r(r),
                         sum(sum(r) - sum(l - 1)),
                         reversed(false),
                         left(NULL),
                         right(NULL)
                         { }
};

typedef Node* pNode;

void get_node(pNode& v, int l, int r) {
    if (v == NULL) {
        v = new Node(l, r);
    }

    return v;
}

void push(pNode v, int l, int r) {
    int mid = (l + r) / 2;

    v->left = get_node(v->left, l, mid);
    v->right = get_node(v->right, mid + 1, r);

    if (v->reversed) {
        v->left->reversed ^= v->reversed;
        v->right->reversed ^= v->reversed;
        swap(v->left, v->right);
        v->reversed ^= true;
    }
}

void reverse(pNode v, int l, int r, int ql, int qr) {
    if (l > qr || ql > r) {
        return;
    }

    if (ql <= l && r <= qr) {
        v->reversed ^= true;
        return;
    }
    
    push(v, l, r);
    int mid = (l + r) / 2;

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
