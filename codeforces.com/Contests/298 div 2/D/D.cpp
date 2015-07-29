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

int cnt[3];
int n, x;
set <pair <int, int> > vec[3];
pair <int, int> res[MAXN];
pair <int, int> zero(-1, -1);

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[i % 3]--;
        cnt[x % 3]++;
        if (x != 0 || zero != make_pair(-1, -1)) {
            vec[x % 3].insert(make_pair(x, i + 1));
        } else {
            zero = make_pair(x, i + 1);
        }
    }

    if (cnt[0] != 0 || cnt[1] != 0 || cnt[2] != 0) {
        puts("Impossible");
        return 0;
    }

    if (zero == make_pair(-1, -1)) {
        puts("Impossible");
        return 0;
    }

    res[0] = zero;

    for (int i = 1; i < n; i++) {
        pair <int, int> to_find(res[i - 1].first + 1, INF);

        set <pair <int, int> > :: iterator it = vec[i % 3].upper_bound(to_find);

        if (it == vec[i % 3].begin()) {
            puts("Impossible");
            return 0;
        }

        it--;
        res[i] = *it;
        vec[i % 3].erase(it);
    }

    puts("Possible");
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i].second);
    }

    puts("");

    /*
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i].first);
    }
    */

    return 0;
}
