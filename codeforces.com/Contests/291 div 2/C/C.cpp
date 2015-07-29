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
const int INF = 2000 * 1000 * 1000;
const int MAXN = 600010;
const long long MOD = 1000 * 1000 * 1000 + 7;
const long long BASE = 7;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Item {
    int pos;
    int h1, h2;

    bool operator < (const Item& it) const {
        if (pos != it.pos) {
            return pos < it.pos;
        }

        if (h1 != it.h1) {
            return h1 < it.h1;
        }

        return h2 < it.h2;
    }
};

set <Item> Set[MAXN][3];
char buf[MAXN];
long long hash[MAXN];
int n, m;
int len;

void fill_hash() {
    long long power = 1;
    for (int i = 1; buf[i]; i++) {
        int cc = buf[i] - 'a' + 1;

        hash[i] = (hash[i - 1] + cc * power) % MOD;
        power = (power * BASE) % MOD;
    }
}

bool recalc_hash(Item& it) {
    if (buf[it.pos + 1]) {
        it.h1 = hash[it.pos];
        it.pos++;
        it.h2 = (hash[len] - hash[it.pos] + 100 * MOD) % MOD;
        return true;
    }

    return false;
}
                    
int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(buf + 1);
        len = strlen(buf + 1);

        fill_hash();
        Item cur;
        cur.pos = 0;
        cur.h1 = 0;
        cur.h2 = hash[len];

        while (recalc_hash(cur)) {
            Set[len][buf[cur.pos] - 'a'].insert(cur);
        }
    }

    for (int i = 0; i < m; i++) {
        gets(buf + 1);
        len = strlen(buf + 1);

        fill_hash();
        Item cur;
        cur.pos = 0;
        cur.h1 = 0;
        cur.h2 = hash[len];

        bool res = false;
        while (!res && recalc_hash(cur)) {
            for (int j = 0; j < 3; j++) {
                if (buf[cur.pos] != j + 'a') {
                    res |= (Set[len][j].count(cur));
                }
            }
        }

        if (res) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}