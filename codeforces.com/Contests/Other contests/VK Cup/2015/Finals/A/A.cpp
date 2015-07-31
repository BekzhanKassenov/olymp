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
const int MAXLET = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    set <int> nick;
    set <int> real;
    Node *next[26];

    void init() {
        memset(next, 0, sizeof next);
    }
};

Node mem[MAXLET];
int lastmem;
Node *root = &mem[lastmem++];
int n;
char s[MAXLET];
long long result;
vector <pair <int, int> > ans;

void add(bool real, int num) {
    Node *cur = root;

    for (int i = 0; s[i]; i++) {
        int let = s[i] - 'a';
        if (cur->next[let] == NULL) {
            cur->next[let] = &mem[lastmem++];
            cur->next[let]->init();
        }

        cur = cur->next[let];
    }

    if (real) {
        cur->real.insert(num);
    } else {
        cur->nick.insert(num);
    }
}

void merge_sets(set <int>& set1, set <int>& set2) {
    if (set1.size() < set2.size()) {
        set1.swap(set2);
    }

    for (set <int> :: iterator it = set2.begin(); it != set2.end(); it++) {
        set1.insert(*it);
    }
}

void solve(Node *v, set <int>& real, set <int>& nick, int depth = 0) {
    set <int>& vreal = v->real;
    set <int>& vnick = v->nick;

    for (int i = 0; i < 26; i++) {
        if (v->next[i] != NULL) {
            solve(v->next[i], vreal, vnick, depth + 1);
        }
    }

    while (!(vreal.empty()) && !(vnick.empty())) {
        result += depth;
        ans.push_back(make_pair(*vreal.begin(), *vnick.begin()));
        vreal.erase(vreal.begin());
        vnick.erase(vnick.begin());
    }

    merge_sets(real, vreal);
    merge_sets(nick, vnick);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    root->init();
    
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        gets(s);
        add(true, i + 1);
    }

    for (int i = 0; i < n; i++) {
        gets(s);
        add(false, i + 1);
    }
    
    set <int> fake1, fake2;
    solve(root, fake1, fake2);

    printf("%I64d\n", result);

    for (size_t i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}
