/****************************************
**          Solution by NU #2          **
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
const int MAXN = 410;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char place[MAXN][50];
int n;

bool g[MAXN][MAXN];
bool used[MAXN];

vector <int> see[MAXN];
vector <int> ans, comp[2];

void dfs(int v, int col) {
    used[v] = true;
    comp[col].push_back(v);

    for (int i = 1; i <= n; i++) {
        if (g[v][i] && !used[i]) {
            dfs(i, col ^ 1);
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        int size;
        scanf("%s %d", place[i], &size);
        see[i].resize(size);

        for (int j = 0; j < size; j++) {
            scanf("%d", &see[i][j]);
        }

        sort(all(see[i]));
        scanf("\n");
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (strcmp(place[i], place[j]) == 0) {
                continue;
            }

            bool edge = false;
            edge |= binary_search(all(see[i]), j);
            edge |= binary_search(all(see[j]), i);

            for (auto person: see[i]) {
                edge |= binary_search(all(see[j]), person);
            }

            for (auto person: see[j]) {
                edge |= binary_search(all(see[i]), person);
            }

            g[i][j] = g[j][i] = edge;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            continue;
        }

        dfs(i, 0);

        int idx = 0;
        if (comp[1].size() < comp[0].size()) {
            idx = 1;
        }

        for (auto person: comp[idx]) {
            ans.push_back(person);
        }

        comp[0].clear();
        comp[1].clear();
    }

    if (ans.empty()) {
        puts("1");
        puts("1");
        return 0;
    }

    printf("%u\n", ans.size());
    for (auto person: ans) {
        printf("%d ", person);
    }

    puts("");
    
    return 0;
}
