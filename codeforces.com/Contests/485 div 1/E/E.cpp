/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
const int MAXA = 1000 * 1000 * 10;
const int LG = 18;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Query {
    int num, u, v, x;
};

int n;
vector <int> g[MAXN];
int a[MAXN];
Query q[MAXN];

struct LCA {
    int tin[MAXN], tout[MAXN];
    int parent[1 << LG][MAXN];

    void dfs(int v, int& t, int par) {
        tin[v] = t++;

        parent[0][v] = par;
        for (int i = 1; i < LG; i++) {
            parent[i][v] = parent[i - 1][parent[i - 1][v]];
        }

        for (int to : g[v]) {
            dfs(to, t, v);
        }
    }

    void build() {
        int t = 0;
        dfs(1, t, 1);
    }

    bool isAnc(int a, int b) {
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    }

    int getLca(int a, int b) {
        for (int i = LG - 1; i >= 0; i--) {
            if (!isAnc(parent[i][a], b)) {
                a = parent[i][a];
            }
        }
        return parent[0][a];
    }
};

LCA lca;

struct VertexRequest {
    int x;
    int qnum;
    bool toMul;
    int res;
};

vector <VertexRequest> vRequests[MAXN];

struct Factorizer {
    vector <int> primes;
    vector <vector<int> > powers;
    map <int, int> overRoot;

    bool prime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    void build() {
        for (int i = 2; i * i <= MAXA; i++) {
            if (prime(i)) {
                primes.push_back(i);
                int maxpower = 0;
                int k = 1;
                while (k <= MAXA) {
                    maxpower++;
                    k *= i;
                }
                powers.emplace_back(maxpower);
            }
        }
    }

    void update(int n, int delta) {
        for (size_t i = 0; i < primes.size(); i++) {
            int pw = 0;
            while (n % i == 0) {
                n /= i;
                pw++;
            }
            powers[i][pw] += delta;
        }
        if (n > 1) {
            overRoot[n] += delta;
        }
    }

    void add(int n) {
        update(n, 1);
    }

    void remove(int n) {
        update(n, -1);
    }

    void solve(int v) {
        sort(all(vRequests[v]), [](const VertexRequest& l, const VertexRequest& r) {
            return l.x < r.x;
        });

        for (size_t i = 0; i < powers.size(); i++) {
            size_t ptr = 0;
            for (size_t j = 0; j < powers[i].size(); j++) {
                while (ptr < vRequests[v].size() && j > vRequests[v][ptr].x) {
                }
            }
        }
    }

};

Factorizer factorizer;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    lca.build();
    factorizer.build();

    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].x);
        q[i].num = i;
    }
    
          
    return 0;
}