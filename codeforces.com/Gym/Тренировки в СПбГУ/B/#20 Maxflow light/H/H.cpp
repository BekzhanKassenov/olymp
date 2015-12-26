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
const int INF = 1 << 30;
const int MAXN = 300;
const int MAXE = 2 * MAXN * MAXN;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Deque {
    int d[MAXN];
    int head, tail;

    Deque() : head(0), tail(0) { }

    bool empty() const {
        return head == tail;
    }

    void clear() {
        head = tail = 0;
    }

    void push_front(int val) {
        head = (head - 1 + MAXN) % MAXN;
        d[head] = val;
    }

    int front() const {
        return d[head];
    }

    void pop_front() {
        head = (head + 1) % MAXN;
    }

    void push_back(int val) {
        d[tail] = val;
        tail = (tail + 1) % MAXN;
    }

    int back() const {
        return d[tail];
    }

    void pop_back() {
        tail = (tail - 1 + MAXN) % MAXN;
    }
};

struct MinCostMaxFlow {
    int to[MAXE];
    int flow[MAXE];
    int cap[MAXE];
    int cost[MAXE];
    int lastE;

    vector <int> g[MAXN];
    int dist[MAXN], par[MAXN], parE[MAXN];
    int id[MAXN];

    Deque deq;

    MinCostMaxFlow() : lastE(0) { }

    void addEdge(int from, int to, int cap, int cost) {
        this->to[lastE] = to;
        this->flow[lastE] = 0;
        this->cap[lastE] = cap;
        this->cost[lastE] = cost;
        g[from].push_back(lastE);
        lastE++;

        this->to[lastE] = from;
        this->flow[lastE] = 0;
        this->cap[lastE] = 0;
        this->cost[lastE] = -cost;
        g[to].push_back(lastE);
        lastE++;
    }

    bool run(int S, int T, int lim) {
        deq.clear();
        
        for (int i = 0; i < MAXN; i++) {
            dist[i] = INF;
            par[i] = -1;
            parE[i] = -1;
            id[i] = 0;
        }

        id[S] = 1;
        dist[S] = 0;
        deq.push_back(S);

        while (!deq.empty()) {
            int v = deq.front();
            deq.pop_front();

            for (size_t i = 0; i < g[v].size(); i++) {
                int idx = g[v][i];

                if (cap[idx] - flow[idx] < lim) {
                    continue;
                }

                if (id[to[idx]] == 0) {
                    deq.push_back(to[idx]);
                    dist[to[idx]] = dist[v] + cost[idx];
                    par[to[idx]] = v;
                } else if (id[to[idx]] == 1) {
                    if (dist[to[idx]] > dist[v] + cost[idx]) {
                        dist[to[idx]] = dist[v] + cost[idx];
                        par[to[idx]] = v;
                    }
                } else {
                    if (dist[to[idx]] > dist[v] + cost[idx]) {
                        dist[to[idx]] = dist[v] + cost[idx];
                        par[to[idx]] = v;
                        parE[to[idx]] = idx;
                        deq.push_front(to[idx]);
                    }
                }
            }
        }

        return par[T] != -1;
    }

    int getMinCostMaxFlow(int S, int T) {
        int addFlow = INF;
        int result = 0;

        while (addFlow > 0) {
            if (run(S, T, addFlow)) {
                for (int v = T; par[v] != -1; v = par[v]) {
                    result += addFlow + cost[parE[v]];
                    flow[parE[v]] += addFlow;
                    flow[parE[v] ^ 1] -= addFlow;
                }
            } else {
                addFlow >>= 1;
            }
        }

        return result;
    }
};

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    return 0;
}
