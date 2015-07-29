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
const int MAXN = 100050;
const int LG = 20;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int x, y;
int anc[MAXN][LG];
vector <int> child[MAXN];
int depth[MAXN], ans[MAXN];
vector <pair <int, int> > query[MAXN];

void dfsANC(int v, int dpth = 0) {
    depth[v] = dpth;

    for (int i = 1; i < LG; i++)
        anc[v][i] = anc[anc[v][i - 1]][i - 1];

    for (size_t i = 0; i < child[v].size(); i++)
        dfsANC(child[v][i], dpth + 1);
}

int get_anc(int v, int k) {
    int cur = v, diff = k;

    for (int i = LG - 1; i >= 0; i--) {
        if (anc[cur][i] == 0)
            continue;

        if (depth[cur] - depth[anc[cur][i]] < diff) {
            diff -= depth[cur] - depth[anc[cur][i]];
            cur = anc[cur][i];
        }
    }

    cur = anc[cur][0];
    if (cur && depth[v] - depth[cur] == k)
        return cur;

    return 0;
}

void merge(deque <int>& deq1, deque <int>& deq2) {
    if (deq1.size() < deq2.size())
        deq1.swap(deq2);

    deque <int> :: iterator it1 = deq1.begin();

    for (deque <int> :: iterator it = deq2.begin(); it != deq2.end(); it++) {
        (*it1) += *it;
        it1++;
    }
}

void dfs(int v, deque <int>& res) {
    deque <int> temp;

    for (size_t i = 0; i < child[v].size(); i++) {
        dfs(child[v][i], temp);
        merge(res, temp);
        temp.clear();
    }

    res.push_front(1);

    for (size_t i = 0; i < query[v].size(); i++) {
        int dst = query[v][i].first;
        int pos = query[v][i].second;

        ans[pos] = *(res.begin() + dst) - 1;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &anc[i][0]);
        child[anc[i][0]].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        if (!anc[i][0])
            dfsANC(i);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);

        int par = get_anc(x, y);
        
        if (par != 0) {
            query[par].push_back(make_pair(y, i));
        }
    }

    deque <int> temp;
    for (int i = 1; i <= n; i++)
        if (!anc[i][0]) {
            dfs(i, temp);
            temp.clear();
        }

    for (int i = 0; i < m; i++)
        printf("%d ", ans[i]);

    puts("");

    return 0;
}
