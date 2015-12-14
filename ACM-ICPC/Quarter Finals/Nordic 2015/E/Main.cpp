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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum ETYPE {
    CLOSE,
    OPEN
};

int n, k;
int start[MAXN], finish[MAXN];

struct Event {
    int t;
    int num;
    ETYPE type;

    bool operator < (const Event& ev) const {
        if (t != ev.t) {
            return t < ev.t;
        }

        return type < ev.type;
    }
};

struct Compare {
    bool operator () (int lhs, int rhs) const {
        if (finish[lhs] != finish[rhs]) {
            return finish[lhs] > finish[rhs];
        }

        return lhs < rhs;
    }
};

multiset <int, Compare> Set;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    vector <Event> events;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &start[i], &finish[i]);
        events.push_back({start[i], i, OPEN});
        events.push_back({finish[i], i, CLOSE});
    }

    sort(all(events));

    int ans = 0;
    for (Event ev: events) {
        if (ev.type == CLOSE) {
            auto it = Set.find(ev.num);
            if (it != Set.end()) {
                Set.erase(it);
                ans++;
            }
        } else {
            if ((int)Set.size() < k) {
                Set.insert(ev.num);
            } else {
                int cand = *Set.begin();

                if (finish[cand] > finish[ev.num]) {
                    Set.erase(Set.begin());
                    Set.insert(ev.num);
                }
            }   
        }
    }

    printf("%d\n", ans);

    return 0;
}
