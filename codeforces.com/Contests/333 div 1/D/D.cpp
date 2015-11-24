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
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    long long size;
    Node *next[26];

    Node() : size(1) {
        memset(next, 0, sizeof(next));
    }

    void append(char c, Node* n) {
        this->next[c - 'a'] = n;
        size += n->size;
    }
};

typedef Node* pNode;

int getSize(pNode v) {
    if (v == NULL) {
        return 0;
    }

    return v->size;
}

void merge(pNode& root1, pNode root2) {
    if (root1 == NULL) {
        root1 = root2;
        return;
    }

    if (root2 == NULL) {
        return;
    }

    root1->size = 1;
    for (int i = 0; i < 26; i++) {
        merge(root1->next[i], root2->next[i]);
        root1->size += getSize(root1->next[i]);
    }
}

void print(pNode root) {
    if (root == NULL) {
        return;
    }

    cerr << root << ' ' << root->size << endl;

    for (int i = 0; i < 26; i++) {
        if (root->next[i] != NULL) {
            cerr << char(i + 'a');
        }
    }

    cerr << endl;

    for (int i = 0; i < 26; i++) {
        print(root->next[i]);
    }
}

int n;
char let[MAXN];
int c[MAXN];
vector <int> g[MAXN];
long long ans;
int cntAns;

pNode dfs(int v, int par = 0) {
    vector <pNode> children;
    children.reserve(g[v].size());

    pNode mx = NULL;
    for (int to: g[v]) {
        if (to != par) {
            children.push_back(dfs(to, v));
            if (mx == NULL || mx->size < children.back()->size) {
                mx = children.back();
            }
        }
    }

    if (mx == NULL) {
        mx = new Node();
    } else {
        for (pNode child: children) {
            if (child != mx) {
                merge(mx, child);
            }
        }
    }

    pNode result = new Node();
    result->append(let[v], mx);

    long long val = c[v] + getSize(result) - 1;

    if (val == ans) {
        cntAns++;
    } else if (val > ans) {
        ans = val;
        cntAns = 1;
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    scanf("\n");
    gets(let + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    printf("%I64d\n%d\n", ans, cntAns);

    return 0;
}
