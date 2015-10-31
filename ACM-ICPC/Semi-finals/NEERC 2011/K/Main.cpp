/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "kingdom"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100000 + 13;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> g[MAXN];
vector <int> leafs;
vector <pair <int, int> > ans;
bool used[MAXN];
int par[MAXN];

void dfs(int v, int p = -1) {
    par[v] = p;

    for (int to: g[v]) {
        if (to != p && !used[to]) {
            dfs(to, v);
        }
    }

    if (g[v].size() == 1u) {
        leafs.push_back(v);
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &from, &to);
        from--; 
        to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    if (n == 2) {
        puts("1");
        puts("1 2");
        return 0;
    }


    for (int i = 0; i < n; i++) {
        if (g[i].size() > 1u) {
            dfs(i);
            break;
        }
    }

    int l = 0, r = leafs.size() - 1;

    while (l < r) {
        ans.emplace_back(leafs[l], leafs[r]);
        l++, r--;
    }

    if (l == r) {
        ans.emplace_back(leafs[l], leafs[0]);
    }

    /*
    vector <pair <int, int > > st;

    st.push_back(make_pair(leafs[0], par[leafs[0]]));

    for (int i = 1; i < (int)leafs.size(); i++) {
        if (st.empty() || par[leafs[i]] == st.back().second) {
            st.push_back(make_pair(leafs[i], par[leafs[i]]));
        } else {
            ans.emplace_back(st.back().first, leafs[i]);
            st.pop_back();
        }
    }


    for (size_t i = 0; i + 1 < st.size(); i += 2) {
        ans.emplace_back(st[i].first, st[i + 1].first);
    }


    if (st.size() & 1) {
        for (size_t i = 0; i < leafs.size(); i++) {
            if (leafs[i] != st.back().first) {
                ans.emplace_back(st.back().first, leafs[i]);            
            }
        }
    }*/

    printf("%u\n", ans.size());
    for (auto p: ans) {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }

    return 0;
}
