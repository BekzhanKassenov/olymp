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

int n;
string s;

struct Node {
    Node* next[26];

    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

bool addLetter(Node* ptr, char c) {
    c -= 'a';
    if (ptr->next[c] != NULL) {
        return false;
    }

    ptr->next[c] = new Node();
    return true;
}

int binpow(int n, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) {
            res = (1ll * res * n) % MOD;
        }

        n = (1ll * n * n) % MOD;
        p >>= 1;
    }

    return res;
}

int fact[2 * MAXN];
int rfact[2 * MAXN];

int C(int N, int K) {
    int ans = fact[N];
    ans = (1ll * ans * rfact[K]) % MOD;
    ans = (1ll * ans * rfact[N - K]) % MOD;

    return ans;
}

int doit(int k) {
    int N = n - k;

    return C(N + k - 1, k - 1);
}

Node* root = new Node();

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;
    cin >> s;

    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < 2 * MAXN; i++) {
        fact[i] = (1ll * fact[i - 1] * i) % MOD;
        rfact[i] = (1ll * rfact[i - 1] * binpow(i, MOD - 2)) % MOD;
    }

    s.resize(unique(all(s)) - s.begin());

    int ans = 0;
    for (size_t i = 0; i < s.size(); i++) {
        Node* cur = root;
        for (size_t j = i; j < s.size(); j++) {
            if (addLetter(cur, s[j])) {
                ans += doit(j - i + 1);
                ans %= MOD;
            }

            cur = cur->next[s[j] - 'a'];
        }
    }

    printf("%d\n", ans);

    return 0;
}
