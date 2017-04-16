/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];
int pos[MAXN];
set <int> empty;
vector <int> start;
bool used[MAXN];

void put(int p, int num) {
    a[p] = num;
    pos[num] = p;
    empty.erase(p);
}

void fix_empties(int v, int global_start) {
    if (empty.count(v)) {
        empty.erase(v);
    }
    
    if (empty.empty()) {
        put(v, global_start);
        return;
    }

    int to = *empty.begin();
    empty.erase(empty.begin());
    put(v, to);

    fix_empties(to, global_start);
}

void fix_chains(int v, int global_start) {
    if (a[v] != 0) {
        fix_chains(a[v], global_start);
        return;
    }

    if (start.empty()) {
        fix_empties(v, global_start);
        return;
    }

    int to = start.back();
    start.pop_back();

    put(v, to);
    fix_chains(to, global_start);
}

int cycle_len(int v) {
    if (used[v]) {
        return 0;
    }

    used[v] = true;
    return 1 + cycle_len(a[v]);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        empty.clear();
        start.clear();
        for (int i = 1; i <= n; i++) {
            a[i] = 0;
            pos[i] = 0;
            used[i] = false;
            empty.insert(i);
        }

        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);

            if (x != 0) {
                put(i, x);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (pos[i] == 0 && a[i] != 0) {
                start.push_back(i);
            }
        }

        if (start.empty()) {
            int v = *empty.begin();
            fix_empties(v, v);
        } else {
            int v = start.back();
            start.pop_back();
            fix_chains(v, v);
        }

        for (int i = 1; i <= n; i++) {
            assert(a[i] != 0);
            assert(pos[i] != 0);
        }

        assert(start.empty());
        assert(empty.empty());

        int answer = 0; 
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                answer += cycle_len(i) - 1;
            }
        }

        printf("%d\n", answer);
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        puts("\n");
    }
    
    return 0;
}
