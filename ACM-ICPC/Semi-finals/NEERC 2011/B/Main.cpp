/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "binary"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int m;

void print(int mask, int len) {
    for (int i = len - 1; i >= 0; i--) {
        if (mask & (1 << i)) {
            putchar('1');
        } else {
            putchar('0');
        }
    }

    putchar('\n');
}

int mask[MAXN], len[MAXN];
set <int> Set;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &m);

    int n = 1;
    while ((1 << n) < m) {
        n++;
    }

    for (int i = 0; i < (1 << n); i++) {
        Set.insert(i);
    }

    int cur = (1 << n);
    int temp = m;

    int i = 0;
    while (cur > temp) {
        mask[i] = i;
        len[i] = n - 1;
        Set.erase(i);
        Set.erase((i << 1) | 1);
        Set.erase(i << 1);

        cur -= 2;
        i++;
        temp--;
    }

    for (int x: Set) {
        mask[i] = x;
        len[i] = n;
        i++;
    }

    for (int i = 0; i < m; i++) {
        print(mask[i], len[i]);
    }

    return 0;
}
