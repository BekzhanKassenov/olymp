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
const int MAXC = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum ETYPE {
    OPEN,
    GOBL,
    CLOSE
};

int n, m;
vector <int> gobl[MAXC];
vector <pair <int, int> > seg[MAXC];

int solve(int pos) {
    vector <pair <int, ETYPE> > events;

    for (size_t i = 0; i < gobl[pos].size(); i++) {
        events.emplace_back(gobl[pos][i], GOBL);
    }

    for (size_t i = 0; i < seg[pos].size(); i++) {
        events.emplace_back(seg[pos][i].first, OPEN);
        events.emplace_back(seg[pos][i].second, CLOSE);
    }

    sort(all(events));
    int ans = 0, bal = 0;

    for (const auto& p: events) {
        switch (p.second) {
            case OPEN:
                bal++;
                break;

            case CLOSE:
                bal--;
                break;

            case GOBL:
                ans += (bal == 0);
                break;
        }
    }

    return ans;
}

void addCircle(int x, int y, int r) {
    int diffY = 0;
    for (int diffX = r; diffX > 0; diffX--) {
        while (sqr(diffY + 1) + sqr(diffX) <= sqr(r)) {
            diffY++;
        }

        if (x - diffX >= 0) {
            seg[x - diffX].emplace_back(y - diffY, y + diffY);
        }

        if (x + diffX < MAXC) {
            seg[x + diffX].emplace_back(y - diffY, y + diffY);
        }
    }

    seg[x].emplace_back(y - r, y + r);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        gobl[x].push_back(y);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);

        addCircle(x, y, r);
    }

    int ans = 0;
    for (int i = 0; i < MAXC; i++) {
        ans += solve(i);
    }

    printf("%d\n", ans);

    return 0;
}
