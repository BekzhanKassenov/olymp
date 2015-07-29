/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}
struct node {
    int p, link, next[26];
    char pch;
    bool leaf;
};
const int N = 100000;
node trie[N];
void set_link(int base, char ch, int cur){
    while (!trie[cur].next[ch - 'a'])
        cur = trie[cur].link;
    trie[base].link = trie[cur].next[ch - 'a'];
}
int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    for (int i = 0; i < 26; ++i)
        trie[0].next[i] = 1;
    
    queue<int> q;
    for (int i = 0; i < 26; ++i){
        if (trie[1].next[i])
            q.push_back(trie[1].next[i]);
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i)
            if (trie[cur].next[i])
                q.push_back(trie[cur].next[i]);
        set_link(cur, trie[cur].pch, trie[trie[cur].p].link);
    }
    
    return 0;
}
