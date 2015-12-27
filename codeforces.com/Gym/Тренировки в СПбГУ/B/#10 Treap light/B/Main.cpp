/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "tree"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 50010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    int key, prior;
    int left, right, parent;
    int num;
};

Node node[MAXN];
int n;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i].key, &node[i].prior);
        node[i].num = i;
    }

    sort(node + 1, node + 1 + n, [] (const Node& a, const Node& b) {
        return a.key < b.key;
    });

    vector <int> st;
    st.push_back(1);
    int root = 1;

    for (int i = 2; i <= n; i++) {
        while (!st.empty() && node[i].prior < node[st.back()].prior) {
            st.pop_back();
        }

        if (st.empty()) {
            node[i].left = root;
            node[root].parent = i;
            root = i;
        } else {
            int v = st.back();

            int rchild = node[v].right;
            if (rchild != 0) {
                node[i].left = rchild;
                node[rchild].parent = i;
            }
            
            node[v].right = i;
            node[i].parent = v;
        }

        st.push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        node[i].parent = node[node[i].parent].num;
        node[i].left = node[node[i].left].num;
        node[i].right = node[node[i].right].num;
    }

    sort(node + 1, node + 1 + n, [] (const Node& a, const Node& b) -> bool {
        return a.num < b.num;
    });

    puts("YES");
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", node[i].parent, node[i].left, node[i].right);
    }

    return 0;

    /*
    #define by(T, x) [] (const T& a, const T& b) -> bool { return a.x < b.x; }

    sort(node, node + n, by(Node, num));
    */
}
