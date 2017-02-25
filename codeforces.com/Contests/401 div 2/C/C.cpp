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
    OPEN,
    QUERY,
    CLOSE
};

struct Event {
    int pos;
    ETYPE type;
    int other_side;
    int qid;

    bool operator < (const Event& e) const {
        if (pos != e.pos) {
            return pos < e.pos;
        }

        return type < e.type;
    }
};

int n, m;
vector <vector <int> > vec;
vector <vector <pair <int, int> > > col_info;
bool ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    vec.assign(n, vector <int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &vec[i][j]);
        }
    }

    vector <Event> events;
    for (int c = 0; c < m; c++) {
        vector <pair <int, int> > col_info;
        col_info.push_back({0, 0});
        for (int i = 1; i < n; i++) {
            if (vec[i][c] >= vec[i - 1][c]) {
                col_info.back().second++;
            } else {
                col_info.push_back({i, i});
            }
        }

        for (const auto& p : col_info) {
            events.push_back({p.first, OPEN, p.second, 0});
            events.push_back({p.second, CLOSE, 0, 0});
        }
    }

    int k;
    scanf("%d", &k);

    for (int i = 1; i <= k; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        events.push_back({l - 1, QUERY, r - 1, i});
    }

    multiset <int> Set;
    sort(all(events));
    for (const auto& event : events) {
        switch (event.type) {
            case OPEN:
                Set.insert(event.other_side);
                break;
            case CLOSE:
                Set.erase(Set.find(event.pos));
                break;
            case QUERY:
                ans[event.qid] = Set.lower_bound(event.other_side) != Set.end();
                break;
        }
    }

    for (int i = 1; i <= k; i++) {
        puts(ans[i] ? "Yes" : "No");
    }

    return 0;
}
