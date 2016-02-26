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
const int MEMSIZE = 1110000;
const int MAXN = 10010;
const int MAXM = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char *ptr;
char mem[MEMSIZE];
char *word[MAXM];
char s[MAXN];
int n, m;

struct Node;

typedef Node* pNode;

struct Node {
    pNode next[26];
    int num;

    Node() {
        memset(next, 0, sizeof(next));
        num = -1;
    }
};

pNode root = new Node();

void addWord(char *w, int num) {
    pNode cur = root;

    for (int i = 0; w[i]; i++) {
        int let = tolower(w[i]) - 'a';
        if (cur->next[let] == NULL) {
            cur->next[let] = new Node();
        }

        cur = cur->next[let];
    }

    cur->num = num;
}

int dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s + 1);

    scanf("%d\n", &m);

    ptr = mem;
    for (int i = 0; i < m; i++) {
        gets(ptr);
        int offset = strlen(ptr) + 1;

        word[i] = ptr;

        ptr += offset;

        addWord(word[i], i);
    }

    memset(dp, 255, sizeof dp);
    dp[0] = 1e9;

    for (int i = 1; i <= n; i++) {
        pNode cur = root;

        for (int j = i; j >= 0; j--) {
            if (cur->num != -1 && dp[j] != -1) {
                dp[i] = cur->num;
                break;
            }

            if (cur->next[s[j] - 'a'] == NULL) {
                break;
            }

            cur = cur->next[s[j] - 'a'];
        }
    }

    vector <char*> ans;

    for (int pos = n; pos > 0; pos -= strlen(word[dp[pos]])) {
        ans.push_back(word[dp[pos]]);
    }

    reverse(all(ans));

    for (auto ptr: ans) {
        printf("%s ", ptr);
    }
    
    return 0;
}
