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

enum TYPE {
    OPEN,
    PT,
};

int n, m, ans[MAXN];
long long l[MAXN], r[MAXN];
long long l1[MAXN], r1[MAXN];
long long a[MAXN];

struct Item {
    long long coord;
    TYPE type;
    int num;
     
    Item() { }

    Item(long long coord, TYPE type, int num) : coord(coord), type(type), num(num) { }

    bool operator < (const Item& it) const {
        if (coord != it.coord) {
            return coord < it.coord;
        }

        if (type != it.type) {
            return type < it.type;
        }

        return false;
    }
};

struct Compare {
    bool operator () (int lhs, int rhs) {
        if (r1[lhs] != r1[rhs]) {
            return r1[lhs] < r1[rhs];
        }
        return lhs < rhs;
    }
};

vector <Item> event;
set <int, Compare> Set;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%I64d%I64d", &l[i], &r[i]);
    }

    for (int i = 0; i + 1 < n; i++) {
        l1[i] = l[i + 1] - r[i];
        r1[i] = r[i + 1] - l[i];
        event.push_back(Item(l1[i], OPEN, i));
    }

    for (int i = 0; i < m; i++) {
        scanf("%I64d", &a[i]);
        event.push_back(Item(a[i], PT, i));
    }

    sort(all(event));
    memset(ans, 255, sizeof ans);

    for (size_t i = 0; i < event.size(); i++) {
        while (!Set.empty()) {
            int pos = *Set.begin();

            if (r1[pos] < event[i].coord) {
                Set.erase(Set.begin());
            } else {
                break;
            }
        }
        
        if (event[i].type == OPEN) {
            Set.insert(event[i].num);
        } else {
            if (!Set.empty()) {
                int pos = *Set.begin();
                Set.erase(Set.begin());
                ans[pos] = event[i].num;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (ans[i] == -1) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", ans[i] + 1);
    }
    
    return 0;
}
