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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[maxn];
map <int, int> cur, next;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    cur[a[0]] = 1;

    for (int i = 1; i < n; i++) {
        next[a[i]] = 1;

        for (map <int, int> :: iterator it = cur.begin(); it != cur.end(); it++) {
            next[a[i] & (it -> F)] = (next[a[i] & (it -> F)] + it -> S) % MOD;
            next[it -> F] = (next[it -> F] + it -> S) % MOD;
        }

        //printf("%d\n", next.size());

        next.swap(cur);
        next.clear();
    }

    printf("%d\n", cur[0]);

    return 0;
}
