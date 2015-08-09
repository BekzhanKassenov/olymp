#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 5 * 100010;
const int MAXM = 4 * MAXN;

struct MaxFlow {
    int to[MAXM];
    int cap[MAXM], flow[MAXM];
    int lastEdge;
    int S, T, lim;

    vector <int> g[MAXN];
    int level[MAXN];
    size_t ptr[MAXN];

    queue <int> q;

    MaxFlow() : lastEdge(0) { }

    void addEdge(int from, int to, int cap) {
        this->to[lastEdge] = to;
        this->cap[lastEdge] = cap;
        this->flow[lastEdge] = 0;
        g[from].push_back(lastEdge++);

        this->to[lastEdge] = from;
        this->cap[lastEdge] = 0;
        this->flow[lastEdge] = 0;
        g[to].push_back(lastEdge++);
    }

    bool bfs() {
        q.push(S);
        memset(level, 255, sizeof level);
        level[S] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (size_t i = 0; i < g[v].size(); i++) {
                int idx = g[v][i];

                if (level[to[idx]] == -1 && cap[idx] - flow[idx] >= lim) {
                    level[to[idx]] = level[v] + 1;
                    q.push(to[idx]);
                }
            }
        }

        return level[T] != -1;
    }

    bool dfs(int v) {
        if (v == T) {
            return true;
        }

        for (; ptr[v] < g[v].size(); ptr[v]++) {
            int idx = g[v][ptr[v]];

            if (level[to[idx]] == level[v] + 1 && 
                cap[idx] - flow[idx] >= lim &&
                dfs(to[idx])) {

                flow[idx] += lim;
                flow[idx ^ 1] -= lim;

                return true;
            }
        }

        return false;
    }

    int getMaxFlow(int x, int y) {
        S = x, T = y;                                           

        lim = 1;
        int flow = 0;

        while (lim > 0) {
            while (bfs()) {
                memset(ptr, 0, sizeof ptr);

                while (dfs(S)) {
                    flow += lim;
                }
            }

            lim >>= 1;
        }

        return flow;
    }   
};

struct DSU {
    int parent[MAXN];

    DSU() {
        for (int i = 0; i < MAXN; i++) {
            parent[i] = i;
        }
    }

    int getParent(int v) {
        if (v == parent[v]) {
            return v;
        }

        return parent[v] = getParent(parent[v]);
    }

    void unite(int x, int y) {
        parent[getParent(x)] = getParent(y);
    }
};

struct Trie {
    map <char, int> next[10 * MAXN];
    int num[10 * MAXN];
    int lastNode;

    int root;
    int size;

    Trie() {
        root = 0;
        size = 0;
        lastNode = 1;
        memset(num, 255, sizeof num);
    }

    int getNumber(char *s) {
        int cur = root;

        for (int i = 0; s[i]; i++) {
            char let = s[i];

            if (!next[cur].count(let)) {
                next[cur][let] = lastNode++;
            }

            cur = next[cur][let];
        }

        if (num[cur] == -1) {
            num[cur] = size++;
        }

        return num[cur];
    }
};

int n, m, k;
char s[15], t[15];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    MaxFlow *maxFlow = new MaxFlow();
    Trie *trie = new Trie();
    DSU *dsu = new DSU();


    scanf("%d %d %d\n", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        scanf("%s %s\n", s, t);

        int x = trie->getNumber(s);
        int y = trie->getNumber(t);

        maxFlow->addEdge(x, y, 1);
        maxFlow->addEdge(y, x, 1);
        dsu->unite(x, y);
    }

    for (int i = 0; i < k; i++) {
        scanf("%s %s\n", s, t);

        int x = trie->getNumber(s);
        int y = trie->getNumber(t);

        if (dsu->getParent(x) != dsu->getParent(y)) {
            puts("0");
        } else {
            printf("%d\n", maxFlow->getMaxFlow(x, y));
        }
    }

    return 0;
}
