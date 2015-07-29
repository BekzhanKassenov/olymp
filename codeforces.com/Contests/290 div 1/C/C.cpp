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
const int MAXN = 210;
const int MAXA = 10010;
const int MAXM = MAXN * MAXN + MAXN + MAXN;

template <typename T>
inline T sqr(T n) {
    return n * n;
}


struct Edge {
    int from, to;
    int flow, cap;

    void init(int f, int t, int c) {
        from = f, to = t;
        flow = 0, cap = c;
    }
};

Edge e[MAXM];
vector <int> g[2 * MAXN];
int S, T, n, last_edge;
int a[MAXN], degree[MAXN];
bool prime[MAXA], used[MAXN];
vector <int> even, odd;
int num[MAXN], last;

void add_edge(int from, int to, int cap) {
    e[last_edge++].init(from, to, cap);
    e[last_edge++].init(to, from, -cap);
}

bool dfs(int v, int flow) {
    if (v == T) {
        return true;
    }

    used[v] = true;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = e[g[v][i]].to;
        int& curflow = e[g[v][i]].flow;
        int& curcap = e[g[v][i]].cap;

        if (!used[to] && curcap - curflow >= flow && dfs(to, flow)) {
            curflow += flow;
            e[g[v][i] ^ 1].flow -= flow;
            return true;
        }
    }

    return false;
}

int get_flow() {
    int curflow = 1 << 31;
    int ans = 0;

    while (curflow > 0) {
        if (dfs(S, curflow)) {
            ans += curflow;
        } else {
            curflow /= 2;
        }
    }

    return ans;
}

void build() {
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < 2 * MAXA; i++) {
        if (prime[i]) {
            for (int j = i * i; j < 2 * MAXA; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    build();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }

    S = last++;
    for (size_t i = 0; i < even.size(); i++) {
        num[even[i]] = last++;
    }

    for (size_t i = 0; i < odd.size(); i++) {
        num[odd[i]] = last++;
    }

    T = last++;

    for (size_t i = 0; i < even.size(); i++) {
        for (size_t j = 0; j < odd.size(); j++) {
            if (prime[a[even[i]] + a[odd[i]]]) {
                add_edge(num[even[i]], num[odd[i]]);
            }
        }
    }
    
    int flow = get_flow();

    if (flow != n) {
        puts("Impossible");
        return 0;
    }

    return 0;
}
