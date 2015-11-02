/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "game"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 210;
const int MAXLEN = 60;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    map <char, int> next;
    bool win;
    bool input;
    bool calced;
};

Node node[6000000];
int root1 = 0, root2 = 1, last = 2;

void add(char s[], int root, bool in) {
    int cur = root;
    for (int i = 0; s[i]; i++) {
        if (!node[cur].next.count(s[i])) {
            node[cur].next[s[i]] = last++;
        }

        cur = node[cur].next[s[i]];
    }

    node[cur].input |= in;
}

int get(char s[], int root, int len) {
    int cur = root;
    for (int i = 0; i < len; i++) {
        if (!node[cur].next.count(s[i])) {
            return -1;
        }

        cur = node[cur].next[s[i]];
    }

    return cur;
}

void print(char *s, int len) {
    for (int i = 0; i < len; i++) {
        cerr << s[i];
    }
}

int n, mx;
char s1[MAXN][MAXLEN];
char s2[MAXN][MAXLEN];
int len[MAXN];

int main() {
#ifdef Local
    double start = clock();
#endif

    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        gets(s1[i]);
        len[i] = strlen(s1[i]);
        mx = max(mx, len[i]);

        strcpy(s2[i], s1[i]);
        reverse(s2[i], s2[i] + len[i]);
    }

    for (int i = 0; i < n; i++) {
        add(s1[i], root1, true);

        for (int j = 1; j < len[i]; j++) {
            add(s1[i] + j, root1, false);
        }
    }

    for (int i = 0; i < n; i++) {
        add(s2[i], root2, true);

        for (int j = 1; j < len[i]; j++) {
            add(s2[i] + j, root2, false);
        }
    }

    char buf1[MAXN];
    char buf2[MAXN];

    for (int l = mx; l > 0; l--) {
        for (int i = 0; i < n; i++) {
            for (int pos = 0; pos <= len[i] - l; pos++) {
                char *ptr1 = buf1 + 1;
                char *ptr2 = buf2 + 1;

                for (int k = 0; k < l; k++) {
                    ptr1[k] = s1[i][pos + k];
                    ptr2[k] = s1[i][pos + k];
                }

                ptr1[l] = '\0';
                ptr2[l] = '\0';

                reverse(ptr2, ptr2 + l);

                int idx1 = get(ptr1, root1, l);
                int idx2 = get(ptr2, root2, l);

                assert(idx1 != -1 && idx2 != -1);

                if (node[idx1].input && node[idx2].input) {
                    node[idx1].win = true;
                    node[idx2].win = true;
                    continue;
                }

                if (node[idx1].calced && node[idx2].calced) {
                    continue;
                }

                bool ans = false;
                for (auto to: node[idx1].next) {
                    if (!node[to.second].win) {
                        ans = true;
                    }
                }

                for (auto to: node[idx2].next) {
                    if (!node[to.second].win) {
                        ans = true;
                    }
                }

                node[idx1].win = ans;
                node[idx2].win = ans;

                node[idx1].calced = true;
                node[idx2].calced = true;
            }
        }
    }

    vector <string> ans;
    char temp[2];
    temp[1] = '\0';

    for (temp[0] = 33; temp[0] <= 126; temp[0]++) {
        int idx1 = get(temp, root1, 1);
        int idx2 = get(temp, root2, 1);

        if (idx1 != -1) {
            if (!node[idx1].win) {
                ans.push_back(string(temp));
            }
        }

        if (idx2 != -1) {
            if (!node[idx2].win) {
                ans.push_back(string(temp));
            }
        }
    }

    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());

    if (ans.empty()) {
        puts("Second");
        return 0;
    }

    puts("First");
    for (auto s: ans) {
        printf("%s", s.c_str());
    }

#ifdef Local
    cerr << "TIME: " << (clock() - start) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

