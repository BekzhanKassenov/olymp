#include <iostream>
#include <cstdio>

using namespace std;

const long long INF = 1e10;

struct Progression {
    long long a0, d;
};

Progression EMPTY = {-INF, -INF};

inline bool operator == (const Progression& lhs, const Progression& rhs) {
    return lhs.a0 == rhs.a0 && lhs.d == rhs.d;
}

inline Progression operator + (const Progression& lhs, const Progression& rhs) {
    if (lhs == EMPTY || rhs == EMPTY) {
        return lhs == EMPTY ? rhs : lhs;
    }

    return {lhs.a0 + rhs.a0, lhs.d + rhs.d};
}

struct Node;

typedef Node* pNode;

struct Node {
    Progression assign, add;
    int maxVal, maxPos;

    pNode left, right;

    Node() :
        assign(EMPTY),
        add(EMPTY),
        maxVal(0),
        left(NULL),
        right(NULL) { }

    void applyFlags() {
        if (assign == EMPTY && add == EMPTY) {
            return false;
        }

        if (assign == EMPTY) {
            
        }
    }
};

pNode& getNode(pNode& v) {
    if (v == NULL) {
        v = new Node();
    }

    return v;
}

int n;

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    scanf("%d\n", &n);

    char type;
    
    while (scanf("%c", &type) == 1 && type != 'E') {
        if (type == 'I') {
            int a, b, d;
            scanf("%d %d %d\n", &a, &b, &d);

        } else {
            int h;
            scanf("%d\n", &h);
        }
    }

    return 0;
}
