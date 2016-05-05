/****************************************
**     Solution by Bekzhan Kassenov    **
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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node;

typedef Node* pNode;

struct Node {
    pNode prev, next, match;
    char let;
};

int n, m;
char s[MAXN], cmd[MAXN];
Node node[MAXN];
pNode start;

void setNext(int pos, pNode val) {
    if (0 <= pos && pos < n) {
        node[pos].next = val;
    }
}

void setPrev(int pos, pNode val) {
    if (0 <= pos && pos < n) {
        node[pos].prev = val;
    }
}

int idx(pNode v) {
    if (v == NULL) {
        return -1;
    }

    return v - node;
}

void debug() {
    for (pNode i = start; i != NULL; i = i->next) {
        cout << idx(i->prev) << ' ' << idx(i->next) << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int pos;
    scanf("%d%d%d\n", &n, &m, &pos);

    gets(s);
    gets(cmd);

    vector <int> st;

    for (int i = 0; i < n; i++) {
        if (st.empty() || s[i] == '(') {
            st.push_back(i);
        } else {
            node[st.back()].match = &node[i];
            node[i].match = &node[st.back()];
            st.pop_back();
        }
    }

    for (int i = 0; i < n; i++) {
        setNext(i - 1, &node[i]);
        setPrev(i + 1, &node[i]);
        node[i].let = s[i];
    }

    start = &node[0];
    pNode ptr = &node[pos - 1];
    for (int i = 0; i < m; i++) {
        if (cmd[i] == 'L') {
            ptr = ptr->prev;
        } else if (cmd[i] == 'R') {
            ptr = ptr->next;
        } else {
            pNode ptr1 = ptr;
            pNode ptr2 = ptr->match;

            if (idx(ptr1) > idx(ptr2)) {
                swap(ptr1, ptr2);
            }

            //cerr << "FT " << idx(ptr1) << ' ' << idx(ptr2) << endl;

            if (ptr1->prev == NULL) {
                pNode res = ptr2->next;
                res->prev = NULL;
                start = res;
                ptr = res;
            } else if (ptr2->next == NULL) {
                pNode res = ptr1->prev;
                res->next = NULL;
                ptr = res;
            } else {
                pNode nxt = ptr2->next;
                pNode prv = ptr1->prev;
                nxt->prev = prv;
                prv->next = nxt;
                ptr = nxt;
            }
        }

//        debug();
    }

    for (pNode i = start; i != NULL; i = i->next) {
        putchar(i->let);
    }

    putchar('\n');
    return 0;
}
