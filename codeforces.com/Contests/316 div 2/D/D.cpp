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
typedef unsigned int uint;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int par[MAXN];
int n, m, v, h;
vector <int> child[MAXN];
vector <pair <int, int> > q[MAXN];
bool ans[MAXN];
char s[MAXN];
vector <uint> *deq[MAXN];

void merge(vector <uint> *deq1, vector <uint> *deq2) {
    if (deq1->size() < deq2->size()) {
        deq1->swap(*deq2);
    }

    auto it1 = deq1->rbegin();
    for (auto it2 = deq2->rbegin(); it2 != deq2->rend(); it2++) {
        (*it1) ^= *it2;
        it1++;
    }
}

void dfs(int v, int dep = 1) {
    deq[v] = NULL;
    for (size_t i = 0; i < child[v].size(); i++) {
        int to = child[v][i];
        dfs(to, dep + 1);
        
        if (deq[v] == NULL || deq[to]->size() > deq[v]->size()) {
            deq[v] = deq[to];
        }
    }

    if (deq[v] == NULL) {
        deq[v] = new vector <uint>();
    }

    for (size_t i = 0; i < child[v].size(); i++) {
        int to = child[v][i];
        if (deq[v] != deq[to]) {
            merge(deq[v], deq[to]);
        }
    }

    deq[v]->push_back(1u << (s[v] - 'a'));

    for (size_t i = 0; i < q[v].size(); i++) {
        int diff = q[v][i].second - dep;

        if (0 <= diff && diff < (int)(deq[v]->size())) {
            ans[q[v][i].first] = __builtin_popcount(*(deq[v]->rbegin() + diff)) <= 1;
        } else {
            ans[q[v][i].first] = true;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);

    for (int i = 2; i <= n; i++) {
        scanf("%d\n", &par[i]);
        child[par[i]].push_back(i);
    }

    gets(s + 1);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v, &h);
        q[v].push_back(make_pair(i, h));
    }
    
    dfs(1);

    for (int i = 0; i < m; i++) {
        if (ans[i]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    
    return 0;
}
