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

int n, x;                       
set <int> ans, cur, temp;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &x);
        temp.clear();

        for (set <int> :: iterator it = cur.begin(); it != cur.end(); it++)
            temp.insert(x | *it);

        temp.insert(x);
        ans.insert(all(temp));
        cur.swap(temp);
    }

    printf("%u\n", ans.size());

    return 0;
}
