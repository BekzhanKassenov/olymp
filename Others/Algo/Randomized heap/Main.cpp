#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

typedef struct Heap* pHeap;

struct Heap {
    int val;
    pHeap l, r;

    Heap() : val(0), l(NULL), r(NULL) {}

    Heap(int val) : val(val), l(NULL), r(NULL) {}
};

pHeap merge(pHeap left, pHeap right) {
    if (!left || !right)
        return (left ? left : right);

    if (left -> val < right -> val)
        swap(left, right);

    if (rand() & 1)
        swap(left -> l, left -> r);

    left -> r = merge(left -> r, right);

    return left -> r;
}

int min(pHeap root) {
    return (root ? root -> val : -1);
}

int pop(pHeap& root) {
    int returnValue = (root ? root -> val : -1);
    
    if (root)
        root = merge(root -> l, root -> r);
    
    return returnValue;
}

void insert(pHeap& root, int key) {
    pHeap newHeap = new Heap(key);
    root = merge(root, newHeap);
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    freopen("log", "a", stderr);

    double start = clock();

    srand(29);

    ios_base :: sync_with_stdio(false);

    int n;

    cin >> n;

    pHeap t = NULL;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        int k;
        switch (c) {
            case '+':
                cin >> k;
                insert(t, k);
                break;

            case '-':
                cout << pop(t) << endl;
                break;

            case '?':
                cout << min(t) << endl;
                break;
        }
    }

    fprintf(stderr, "%.3lf               ", ((clock() - start) / CLOCKS_PER_SEC));

    return 0;
}
