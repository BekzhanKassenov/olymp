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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Node {
    int next[26];
    bool used;

    void init() {
        memset(next, 0, sizeof next);
        used = false;
    }
};

Node node[100 * 100];
int last;

int T;
char s[MAXN];
int n, k;

void add(char s[]) {
    int cur = 0;
    for (int i = 0; s[i]; i++) {
        int let = s[i] - 'a';
        if (node[cur].next[let] == 0) {
            node[cur].next[let] = last;
            node[last].init();
            last++;
        }

        cur = node[cur].next[let];
    }
}

vector <int> len;

bool go(int pos, int num) {
    bool ans = false;

    if (num == k - 1) {
        if (pos == n) {
            return ans = false;
        }

        int cur = 0;
        for (int i = pos; i < n; i++) {
            int let = s[i] - 'a';
            cur = node[cur].next[let];
        }

        if (node[cur].used) {
            return ans = false;
        }

        len.push_back(n - pos);
        return ans = true;
    }

    int cur = 0;
    for (int i = pos; i < n; i++) {
        int let = s[i] - 'a';
        cur = node[cur].next[let];

        if (!node[cur].used) {
            node[cur].used = true;
            len.push_back(i - pos + 1);

            if (go(i + 1, num + 1)) {
                return ans = true;
            }

            len.pop_back();
            node[cur].used = false;
        }
    }

    return ans = false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &T);

    while (T--) {
        gets(s);
        n = strlen(s);

        scanf("%d\n", &k);

        last = 1;
        node[0].init();

        for (int i = 0; i < n; i++) {
            add(s + i);
        }

        len.clear();

        if (!go(0, 0)) {
            puts("NO");
        } else {
            puts("YES");

            int pos = 0;
            for (int i = 0; i < k; i++) {
                char buf = s[pos + len[i]];
                s[pos + len[i]] = '\0';
                
                puts(s + pos);
                
                s[pos + len[i]] = buf;
                pos += len[i];
            }
        }
    }
    
    return 0;
}
