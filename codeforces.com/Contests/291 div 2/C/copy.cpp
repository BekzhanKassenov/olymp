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
    Node* next[3];
    bool leaf;

    Node() {
        memset(next, 0, sizeof next);
        leaf = false;
    }
};

Node* root = new Node();

void add(char s[]) {
    Node* cur = root;

    for (int i = 0; s[i]; i++) {
        int cc = s[i] - 'a';
        if (cur->next[cc] == NULL) {
            cur->next[cc] = new Node();
        }

        cur = cur->next[cc];
    }

    cur->leaf = true;
}

bool check(char s[], int pos = 0, int err = 0, Node* cur = root) {
    if (!s[pos]) {
        return cur->leaf;
    }
    
    int cc = s[pos] - 'a';
    if (cur->next[cc] == NULL) {
        if (err == 1) {
            return false;
        }

        bool ans = false;
        for (int i = 0; i < 3; i++) {
            if (cur->next[i] != NULL) {
                ans |= check(s, pos + 1, err + 1, cur->next[i]);
            }
        }

        return ans;
    }

    return check(s, pos + 1, err, cur->next[cc]);
}

char buf[MAXN];
int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, m;
    scanf("%d %d\n", &n, &m);
    
    for (int i = 0; i < n; i++) {
        gets(buf);
        add(buf);
    }

    for (int i = 0; i < m; i++) {
        gets(buf);
        if (check(buf)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}
