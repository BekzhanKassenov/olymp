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

int n, p[MAXN], a, b;
int deg[MAXN];
set <int> Set;
map <int, int> Map;

void dfs(int num, int par = -1) {
    int aa = a - num;
    int bb = b - num;

    if (Set.count(aa) && aa != par) {
        dfs(aa, num);
        
        if (Set.count(num) && Set.count(aa)) {
            Map[num] = 0;
            Map[aa] = 0;
            Set.erase(num);
            Set.erase(aa);
        }
    } else if (Set.count(bb) && bb != par) {
        dfs(bb, num);

        if (Set.count(num) && Set.count(bb)) {
            Map[num] = 1;
            Map[bb] = 1;
            Set.erase(num);
            Set.erase(bb);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d", &n, &a, &b);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        Set.insert(p[i]);
    }

    if (a == b) {
        for (int i = 0; i < n; i++) {
            if (Set.count(p[i]) && Set.count(a - p[i])) {
                Set.erase(p[i]);
                Set.erase(a - p[i]);
            }
        }

        if (Set.empty()) {
            puts("YES");
            for (int i = 0; i < n; i++)
                printf("1 ");
            puts("");
        } else {
            puts("NO");
        }

        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (Set.count(a - p[i]))
            deg[i]++;

        if (Set.count(b - p[i]))
            deg[i]++;

        if (deg[i] == 0) {
            puts("NO");
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
        if (deg[i] == 1)
            dfs(p[i]);

    if (!Set.empty()) {
        puts("NO");
        return 0;
    }

    puts("YES");

    for (int i = 0; i < n; i++)
        printf("%d ", Map[p[i]]);

    puts("");

    return 0;
}
