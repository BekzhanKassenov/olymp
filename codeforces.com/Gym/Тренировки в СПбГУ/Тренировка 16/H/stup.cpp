/****************************************
**          Solution by NU #2          **
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
const int MAXN = 135 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, x;
int a[150000];
int maxpos;

void insert(int pos, int val) {
    if (a[pos] == 0) {
        a[pos] = val;
    } else {
        insert(pos + 1, a[pos]);
        a[pos] = val;
    }

    maxpos = max(maxpos, pos);
}

int main() {
    freopen("in", "r", stdin);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        insert(x, i);
    }

    for (int i = 1; i <= maxpos; i++) {
        printf("%d%c", a[i], " \n"[i == maxpos]);
    }

    return 0;
}
