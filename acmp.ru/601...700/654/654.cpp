#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <list>
#include <vector>

using namespace std;

const int MAXN = 200010;
const int INF = 2000 * 1000 * 1010;

struct Node;

typedef Node* pNode;

struct Node {
    int data;
    pNode next, prev;

    Node() :
        data(0),
        next(NULL),
        prev(NULL) { }
};

struct List {
    pNode head, tail;

    List() :
        head(NULL),
        tail(NULL) { }

    void push_back(int data) {
        pNode node = new Node;
        node->data = data;

        if (head == NULL && tail == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void erase(pNode node) {
        if (node == head) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }

            delete node;

        } else if (node == tail) {
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }

            delete node;

        } else {
            pNode p = node->prev, n = node->next;

            p->next = n;
            n->prev = p;

            delete node;
        }
    }
};

struct Compare {
    bool operator() (pNode a, pNode b) const {
        if (a->data != b->data) {
            return a->data < b->data;
        }

        return a < b;
    }
};

int n;
int a[MAXN];
List l;
set <pNode, Compare> Set;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    n = unique(a, a + n) - a;

    for (int i = 0; i < n; i++) {
        l.push_back(a[i]);
    }

    for (pNode it = l.head; it != NULL; it = it->next) {
        Set.insert(it);
    }

    long long ans = 0;
    while (!Set.empty()) {
        pNode it = *Set.begin();
        Set.erase(Set.begin());

        pNode next = it->next;
        pNode prev = it->prev;

        int diff = INF;
        if (prev != NULL) {
            diff = min(diff, prev->data);
        }

        if (next != NULL) {
            diff = min(diff, next->data);
        }

        if (diff != INF) {
            diff = diff - it->data;
            ans += diff;
        }

        if (prev != NULL && next != NULL && prev->data == next->data) {
            Set.erase(Set.find(next));
            l.erase(next);
        }

        l.erase(it);
    }

    printf("%I64d\n", ans);

    return 0;
}
