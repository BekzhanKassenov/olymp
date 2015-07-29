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
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    Node *left, *right;
    char *value;

    Node() { } 

    Node(Node *left, Node *right, char *value) : left(left), right(right), value(value) { }
};

typedef Node* pNode;

pNode getLeft(pNode v) {
    if (v == NULL)
        return NULL;

    return v -> left;
}

pNode getRight(pNode v) {
    if (v == NULL)
        return NULL;

    return v -> right;
}

pNode update(pNode v, int l, int r, int pos, char* val) {
    if (l == r)
        return new Node(NULL, NULL, val);

    int mid = (l + r) / 2;

    pNode result;

    if (pos <= mid)
        result = new Node(update(getLeft(v), l, mid, pos, val), getRight(v), NULL);
    else
        result = new Node(getLeft(v), update(getRight(v), mid + 1, r, pos, val), NULL);

    return result;
}

char* find(pNode v, int l, int r, int pos) {
    if (v == NULL)
        return NULL;

    if (l == r)
        return v -> value;

    int mid = (l + r) / 2;

    if (pos <= mid)
        return find(v -> left, l, mid, pos);

    return find(v -> right, mid + 1, r, pos);
}

pNode root = NULL;
pNode version[MAXN];
char mem[4000000], temp[100];
map <string, int> num;
int memptr, numsize;
int n, q, k, par[MAXN];
vector <pair <int, char*> > prop[MAXN];
vector <int> child[MAXN];

void dfs(int v, pNode prevVer) {
    for (size_t i = 0; i < prop[v].size(); i++)
        prevVer = update(prevVer, 0, numsize - 1, prop[v][i].first, prop[v][i].second);

    version[v] = prevVer;

    for (size_t i = 0; i < child[v].size(); i++)
        dfs(child[v][i], prevVer);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d\n", &par[i], &k);
        prop[i].resize(k);
        child[par[i]].push_back(i);

        for (int j = 0; j < k; j++) {
            gets(temp);

            char *ptr = temp;
            while (*ptr != '=')
                ptr++;

            *ptr = '\0';
            strcpy(mem + memptr, ptr + 1);            
            
            string _temp(temp);

            if (!num.count(_temp)) {
                num[_temp] = numsize;
                numsize++;
            }

            prop[i][j].first = num[_temp];
            prop[i][j].second = mem + memptr;

            memptr += strlen(mem + memptr) + 1;
        }
    }

    for (int i = 1; i <= n; i++)
        if (par[i] == 0)
            dfs(i, root);
    
    scanf("%d", &q);

    while (q--) {
        scanf("%d %s", &k, temp);

        string _temp(temp);

        if (!num.count(temp)) {
            puts("N/A");
            fflush(stdout);
            continue;
        }

        char *res = find(version[k], 0, numsize - 1, num[temp]);

        if (res == NULL)
            puts("N/A");
        else
            puts(res);

        fflush(stdout);
    } 
    
    return 0;
}
