/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

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
const int MAXM = 4 * MAXN * MAXN;
const int MAXK = 20010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MaxFlow {
    int to[MAXM];
    int flow[MAXM], cap[MAXM];
    int lastEdge;
    
    vector <int> g[MAXN];
    bool used[MAXN];
    
    int S, T;
    
    MaxFlow() : lastEdge(0) { }
    
    void addEdge(int from, int to, int cap) {
        this->to[lastEdge] = to;
        this->flow[lastEdge] = 0;
        this->cap[lastEdge] = cap;
        g[from].push_back(lastEdge++);
        
        this->to[lastEdge] = from;
        this->flow[lastEdge] = 0;
        this->cap[lastEdge] = 0;
        g[to].push_back(lastEdge++);
    }
    
    bool dfs(int v, int T, int curFlow) {
        if (v == T) {
            return true;
        }
        
        used[v] = true;
        
        for (size_t i = 0; i < g[v].size(); i++) {
            int idx = g[v][i];
            
            if (!used[to[idx]] && cap[idx] - flow[idx] >= curFlow &&
                dfs(to[idx], T, curFlow)) {
                
                flow[idx] += curFlow;
                flow[idx ^ 1] -= curFlow;
                return true;   
            }
        }
        
        return false;
    }
    
    int getMaxFlow(int S, int T) {
        this->S = S;
        this->T = T;
        
        int curFlow = 1024;
        int resFlow = 0;
        
        while (curFlow > 0) {
            memset(used, false, sizeof(used));
            
            if (dfs(S, T, curFlow)) {
                resFlow += curFlow;
            } else {
                curFlow >>= 1;
            }
        }
        
        return resFlow;
    }
    
    void ansDFS(int v, vector <int>& comp) {
        comp.push_back(v);
        used[v] = true;
        
        for (size_t i = 0; i < g[v].size(); i++) {
            int idx = g[v][i];
            
            if (flow[idx] != 0 && !used[to[idx]] && to[idx] != S && to[idx] != T) {
                ansDFS(to[idx], comp);
            }
        }
    }
    
    void getAns(vector <vector <int> >& ans) {
        ans.clear();
        memset(used, false, sizeof(used));
        vector <int> temp;
        
        for (int i = 0; i < lastEdge; i++) {
            if (!used[to[i]] && to[i] != S && to[i] != T) {
                ansDFS(to[i], temp);
                ans.push_back(temp);
                temp.clear();
            }
        }
    }
};

int n;
int a[MAXN];
bool prime[MAXK];
MaxFlow maxFlow;

void build() {
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    
    for (int i = 2; i < MAXK; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAXK; j += i) {
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
    
    int S = n + 1, T = n + 2;
    
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            maxFlow.addEdge(S, i, 2);
            
            for (int j = 0; j < n; j++) {
                if (a[j] % 2 == 1 && prime[a[i] + a[j]]) {
                    maxFlow.addEdge(i, j, 1);
                }
            }
        } else {
            maxFlow.addEdge(i, T, 2);
        }
    }
    
    int flow = maxFlow.getMaxFlow(S, T);
    
    if (flow != n) {
        puts("Impossible");
        return 0;
    }

    vector <vector <int> > ans;
    maxFlow.getAns(ans);    
    
    printf("%lu\n", ans.size());
    
    for (size_t i = 0; i < ans.size(); i++) {
        printf("%lu", ans[i].size());
        for (size_t j = 0; j < ans[i].size(); j++) {
            printf(" %d ", ans[i][j] + 1);
        }
        
        puts("");
    }
    
    return 0;
}
