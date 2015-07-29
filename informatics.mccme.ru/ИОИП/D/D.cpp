#include <iostream>        
#include <algorithm>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

typedef struct list_item* plist_item;

struct list_item {
    int val;
    plist_item prev, next;

    list_item() : val(0), prev(NULL), next(NULL) {}

    list_item(int val) : val(val), prev(NULL), next(NULL) {}
};

struct item {
    int l, r;
    plist_item begin;

    item() {}

    item(int l, int r, plist_item begin) : l(l), r(r), begin(begin) {}

    bool operator < (const item& p) const {
        if (r - l != p.r - p.l)
            return (r - l < p.r - p.l);

        if (r + l != p.r + p.l)
            return (r + l > p.l + p.r);
                    
        return (begin < p.begin);
    }
};

set <item> s;

struct list {
    plist_item begin, end;

    list() : begin(NULL), end(NULL) {}

    void push_back(int val) {
        plist_item it = new list_item(val);
        
        if (begin == NULL) {
            begin = it;
            end = it;
        } else {
            end -> next = it;
            it -> prev = end;
            end = it;
        }
    }

    void erase(plist_item it) {
        plist_item left = it, right = it -> next;

        if (left == begin && right == end) {
            begin = end = NULL;
            return;
        }

        if (left == begin) {
            s.erase(item(right -> val, right -> next -> val, right));
            begin = right -> next;
        } else if (right == end) {
            s.erase(item(left -> prev -> val, left -> val, left -> prev));
            end = left -> prev;
        } else {
            s.erase(item(right -> val, right -> next -> val, right));
            s.erase(item(left -> prev -> val, left -> val, left -> prev));
            plist_item lprev = left -> prev;
            plist_item rnext = right -> next;

            s.insert(item(lprev -> val, rnext -> val, lprev));

            lprev -> next = rnext;
            rnext -> prev = lprev;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector <int> a(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    list l;

    for (int i = 0; i < 2 * n; i++) {
        l.push_back(a[i]);

        if (i) 
            s.insert(item(a[i - 1], a[i], l.end -> prev));
    }

    vector <int> nevill, harry;

    while (!s.empty()) {
        item cur = *s.begin();
        s.erase(s.begin());

        l.erase(cur.begin);

        nevill.push_back(cur.l);
        harry.push_back(cur.r);
    }

    for (int i = 0; i < n; i++)
        cout << harry[i] << ' ';
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << nevill[i] << ' ' ;
    cout << endl;

    return 0;
}
