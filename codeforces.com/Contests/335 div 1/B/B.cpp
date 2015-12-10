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

struct Edge {
    int from, to;
    int cost, MST;
    int num;
};

bool cmp(const Edge& a, const Edge& b) {
    if (a.cost != b.cost) {
        return a.cost < b.cost;
    }

    return a.MST > b.MST;
}

bool cmpNum(const Edge& a, const Edge& b) {
    return a.num < b.num;
}

int n, m;
Edge a[MAXN];

set <pair <int, int> > Set;

void updateSet(int nedge) {
    for (int i = 2; i < nedge && (int)Set.size() < m; i++) {
        Set.emplace(i, nedge);
    }
}

pair <int, int> getEdge() {
    if (Set.empty()) {
        return {-1, -1};
    }

    pair <int, int> res = *Set.begin();
    Set.erase(Set.begin());

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a[i].cost, &a[i].MST);
        a[i].num = i;
    }

    sort(a, a + m, cmp);

    int lastMST = 2;

    for (int i = 0; i < m; i++) {
        if (a[i].MST == 1) {
            a[i].from = 1;
            a[i].to = lastMST;
            
            updateSet(lastMST);
            lastMST++;
        } else {
            pair <int, int> lastEdge = getEdge();
            if (lastEdge == make_pair(-1, -1)) {
                puts("-1");
                return 0;
            }

            a[i].from = lastEdge.first;
            a[i].to = lastEdge.second;
        }
    }

    sort(a, a + m, cmpNum);
    for (int i = 0; i < m; i++) {
        printf("%d %d\n", a[i].from, a[i].to);
    }

    return 0;
}
