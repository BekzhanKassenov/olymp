/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File ""

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

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

const int len = 256;

struct Block {
    int a[len];

    int g;

    Block() { }

    void init(int* t, int l, int r) {
        g = 0;

        for (int i = l; i <= r; i++) {
            a[i - l] = t[i];
            g = gcd(g, t[i]);
        }
    }

    int get(int l, int r) {
        int res = 0;

        for (int i = l; i <= r; i++)
            res = gcd(res, a[i]);
        
        return res;
    }
};


struct Decomp {
    Block a[len];

    Decomp() { }

    Decomp(int* t, int n) {
        for (int i = 0; i < n; i += len) {
            a[i / len].init(t, i, min(i + len - 1, n - 1));
        }
    }

    int get(int l, int r) {
        int block_l = l / len;
        int block_r = r / len;

        int pos_l = l % len;
        int pos_r = r % len;
        
        if (block_l == block_r) {
            return a[block_l].get(pos_l, pos_r);
        }

        int res = gcd(a[block_l].get(pos_l, len - 1), a[block_r].get(0, pos_r));

        for (int i = block_l + 1; i < block_r; i++)
            res = gcd(res, a[i].g);
    
        return res;
    }
};

int n, m, a[50010], l, r;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Decomp deco(a, n);

    stringstream ss;

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        
        l--, r--;

        ss << deco.get(l, r) << endl;
    }

    puts(ss.str().c_str());

    return 0;
}
