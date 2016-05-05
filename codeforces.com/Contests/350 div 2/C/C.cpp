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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
map <int, int> cnt;
int m;
int b[MAXN], c[MAXN];

int get(int pos) {
    if (cnt.count(pos)) {
        return cnt[pos];
    }

    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
    }

    int idx = 1;
    int bans = 0, cans = 0;
    for (int i = 1; i <= m; i++) {
        int bcur = get(b[i]);
        int ccur = get(c[i]);

        if (bcur > bans || (bcur == bans && ccur > cans)) {
            idx = i;
            bans = bcur;
            cans = ccur;
        }
    }

    printf("%d\n", idx);
    
    return 0;
}
