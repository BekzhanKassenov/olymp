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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    int next[26];
    int sufflink;
    int len;
} tree[MAXN];

int tree_last = 1;
char s[MAXN];
int n, maxsuff;
long long ans;

void add_letter(int pos, char c) { 
    int cur = maxsuff;

    while (tree[cur].sufflink != cur && s[pos - tree[cur].len - 1] != c)
        cur = tree[cur].sufflink;

    if (tree[cur].next[c - 'a'] == 0) {         
        maxsuff = tree_last;
        tree[cur].next[c - 'a'] = tree_last;    
        tree[tree_last].len = tree[cur].len + 2;

        do {
            cur = tree[cur].sufflink;
        } while (tree[cur].sufflink != cur && s[pos - tree[cur].len - 1] != c);

        tree[tree_last].sufflink = tree[cur].next[c - 'a'];
        tree_last++;
    } else                                           
        maxsuff = tree[cur].next[c - 'a'];          
}

void initialize() {
    tree[tree_last].len = -1;
    tree[tree_last++].sufflink = 1;

    tree[tree_last].len = 0;
    tree[tree_last++].sufflink = 1;
    maxsuff = 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    gets(s);
    n = strlen(s);

    initialize();

    for (int i = 0; i < n; i++)
        add_letter(i, s[i]);

    printf("%I64d\n", ans);

    return 0;
}
