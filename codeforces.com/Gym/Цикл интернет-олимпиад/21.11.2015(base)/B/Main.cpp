/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "bow"

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

enum TYPE {
    OPEN,
    CLOSE
};

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n;
    scanf("%d", &n);

    vector <pair <int, TYPE> > events;
    for (int i = 0; i < n; i++) {
        int x, d;
        scanf("%d%d", &x, &d);
        events.emplace_back(x - d, OPEN);
        events.emplace_back(x + d, CLOSE);
    }

    sort(all(events));
    int bal = 0;
    int ans = 0;
    bool found = false;
    for (const auto& event : events) {
        if (event.second == OPEN) {
            bal++;
        }

        if (bal == n) {
            ans = event.first;
            found = true;
        }

        if (event.second == CLOSE) {
            bal--;
        }
    }

    if (!found) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
