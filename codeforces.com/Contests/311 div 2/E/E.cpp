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
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool calced[MAXN][MAXN];
bool good[MAXN][MAXN];
char s[MAXN];
int n, k;

bool calc(int l, int r) {
    if (calced[l][r]) {
        return good[l][r];
    }

    if (l >= r) {
        return true;
    }

    calced[l][r] = true;
    bool& ans = good[l][r];

    if (l & 1) {
        ans = (s[l] == s[r]) && calc(l + 2, r - 2);
    } else {
        ans = calc(l + 1, r - 1);
    }

    return ans;
}

struct Trie {
    Trie* next[2];

    Trie() {
        memset(next, 0, sizeof next);
    }
};

Trie *root = new Trie();



int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s + 1);
    n = strlen(s + 1);
    
    scanf("%d", &k);
    
    for (int i = 1; i <= n; i++) {
        add(i);
    }



    return 0;
}
