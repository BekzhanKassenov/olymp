#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef unsigned long long ull;

const int MAXD = 45;
const int MAXK = 40010;
const int MAXM = 200;
const int MAGIC = 2;

#define all(x) (x).begin(), (x).end()

bool isZeroA;
int k, m, n;
int a[MAXK][MAXD], b[MAXM][MAXD], rev[MAXK][MAGIC];

int mod[MAGIC] = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9};
int x[MAGIC] = {13, 139};
map <ull, int> Map;
bool onlyZero;

int binpow(int n, int st, int MOD) {
    int res = 1;

    while (st) {
        if (st & 1)
            res = (1ll * res * n) % MOD;

        n = (1ll * n * n) % MOD;
        st >>= 1;
    }

    return res;
}

int calc(int P[], int len, int x, int mod) {
    int res = 0;

    for (int i = len; i >= 0; i--)
        res = ((1ll * res * x + P[i]) % mod + mod) % mod;

    return res;
}

ull hash(const vector <int>& v) {
    return (ull(v[0]) * mod[1]) + ull(v[1]);
}

int main() {
#ifdef Local    
    assert(freopen("in", "r", stdin));
#endif
    srand(0xdeadbeef);
    x[0] = 100 + rand();

    do {   
        x[1] = 1000 + rand();
    } while (x[1] == x[0]);

    scanf("%d%d%d", &k, &m, &n);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++)
            scanf("%d", &a[i][j]);
        
        vector <int> val(MAGIC);

        for (int pos = 0; pos < MAGIC; pos++) {
            val[pos] = calc(a[i], n, x[pos], mod[pos]);
            rev[i][pos] = binpow(val[pos], mod[pos] - 2, mod[pos]);
        }

        ull hh = hash(val);

        if (!hh)
            isZeroA = true;

        assert(!Map.count(hh));

        Map[hh] = i;
    }

    for (int i = 0; i < m; i++) {
        bool flag = false;
        for (int j = 0; j <= 2 * n; j++) {
            scanf("%d", &b[i][j]);
            if (b[i][j])
                flag = true;
        }

        if (!flag) {
            if (isZeroA)
                printf("%d\n", k);
            else
                puts("0");
            continue;
        }

        vector <int> val(MAGIC);
        int ans = 0;

        for (int pos = 0; pos < MAGIC; pos++)   
            val[pos] = calc(b[i], 2 * n, x[pos], mod[pos]);

        for (int j = 0; j < k; j++) {
            vector <int> temp(MAGIC);

            for (int pos = 0; pos < MAGIC; pos++)
                if (rev[j][pos])
                    temp[pos] = (1ll * val[pos] * rev[j][pos]) % mod[pos];
            
            ull hh = hash(temp);

            if (Map.count(hh) && Map[hh] <= j && rev[j][0] && rev[j][1])
                ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}
