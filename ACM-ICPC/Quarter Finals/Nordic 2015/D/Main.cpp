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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Event {
    bool open;
    int t;

    bool operator < (const Event& e) const {
        if (t != e.t) {
            return t < e.t;
        }

        if (!open && e.open) {
            return true;
        }

        return false;
    }
};

int n, k;
multiset <Event> Set;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    
    int num = 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Set.insert({true, x});
    }

    int ans = 0;
    while (!Set.empty()) {
        bool open = Set.begin()->open;
        int t = Set.begin()->t;

        Set.erase(Set.begin());

        if (!open) {
            num++;
        } else {
            if (num == 0) {
                num = k;
                ans++;
            }

            num--;
            Set.insert({false, t + 1000});
        }
    }

    printf("%d\n", ans);

    return 0;
}
