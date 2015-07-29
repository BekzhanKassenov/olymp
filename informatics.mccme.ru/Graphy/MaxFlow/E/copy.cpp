#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

#define hash __hash123

const int MOD1 = 1000 * 1000 * 1000 + 7;
const int BASE1 = 39;
const int MOD2 = 1000 * 1000 * 1000 + 9;
const int BASE2 = 37;
const int MAXN = 5 * 100010;

struct Compare {
    bool operator () (const string& s, const string& t) {
        if (s.size() != t.size())
            return s.size() < t.size();

        string :: const_iterator itt = t.begin();
        for (string :: const_iterator its = s.begin(); its != s.end(); its++, itt++) {
            if (*its != *itt)
                return *its < *itt;
        }

        return false;
    }
};

map <long long, int> Map;
int n, m, k, lastEdge;
int num;
vector <int> g[MAXN];
int to[4 * MAXN], flow[4 * MAXN];
int DSUparent[MAXN], DSUsize[MAXN];
size_t ptr[MAXN];
string s, t;
int dist[MAXN], dist_time[MAXN], timer = 1;

long long hash(const string& s, int base, int mod) {
    long long res = 0;

    for (size_t i = 0; i < s.size(); i++) {
        res *= base;
        res += s[i];
        res %= mod;
    }

    return res;
}

long long hash(const string& s) {
    long long h1 = hash(s, BASE1, MOD1);
    long long h2 = hash(s, BASE2, MOD2);

    return (h1 << 32) ^ h2;
}

struct que {
    int arr[MAXN];
    int head, tail;

    que() : head(0), tail(0) { }

    void push(int val) {
        arr[tail++] = val;
    }

    int front() {
        return arr[head];
    }

    void pop() {
        head++;
    }

    bool empty() {
        return head >= tail;
    }

    void clear() {
        head = tail = 0;
    }
} q;

bool bfs(int S, int T) {
    q.clear();
    q.push(S);
    
    timer++;
    dist[S] = 0;
    dist_time[S] = timer;
    ptr[S] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ptr[v] = 0;

        for (size_t i = 0; i < g[v].size(); i++) {
            int To = to[g[v][i]];
            int fl = flow[g[v][i]];

            if (fl == 0 && dist_time[To] < timer) {
                dist[To] = dist[v] + 1;
                dist_time[To] = timer;
                q.push(To);
            }
        }
    }

    return dist_time[T] == timer;
}

bool dfs(int v, int T) {
    if (v == T)
        return true;

    for (; ptr[v] < g[v].size(); ptr[v]++) {
        int index = g[v][ptr[v]];

        int To = to[index];
        int fl = flow[index];

        if (fl == 0 && dist[To] == dist[v] + 1 && dist_time[To] == timer && dfs(To, T)) {
            flow[index] = 1;
            flow[index ^ 1] = 0;
            return true;
        }
    }

    return false;
}

int DSUget_parent(int a) {
    if (DSUparent[a] == a)
        return a;

    return DSUparent[a] = DSUget_parent(DSUparent[a]);
}

void DSUunite(int a, int b) {
    a = DSUget_parent(a);
    b = DSUget_parent(b);

    if (a == b)
        return;

    if (DSUsize[a] < DSUsize[b]) {
        DSUparent[a] = b;
        DSUsize[b] += DSUsize[a];
    } else {
        DSUparent[b] = a;
        DSUsize[a] += DSUsize[b];
    }
}

int dinic(int S, int T) {
    int resFlow = 0;
    
    if (DSUget_parent(S) != DSUget_parent(T))
        return resFlow;

    for (int i = 0; i < lastEdge; i++) {
        flow[i] = (i & 1);
    }
    
    while (bfs(S, T)) {
        while (dfs(S, T))
            resFlow++;
    }
    
    return resFlow;
}


void init(int To, int fl) {
    to[lastEdge] = To;
    flow[lastEdge] = fl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        DSUparent[i] = i;
        DSUsize[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> s >> t;

        long long hs = hash(s);
        long long ht = hash(t);

        if (Map.find(hs) == Map.end()) {
            Map[hs] = num;
            num++;
        }

        if (Map.find(ht) == Map.end()) {
            Map[ht] = num;
            num++;
        }

        int x = Map[hs];
        int y = Map[ht];

        DSUunite(x, y);

        for (int j = 0; j < 2; j++) {
            init(y, 0);
            g[x].push_back(lastEdge);
            lastEdge++;
            
            init(x, 1);
            g[y].push_back(lastEdge);
            lastEdge++;

            swap(x, y);
        }
    }

    while (k--) {
        cin >> s >> t;

        int x = Map[hash(s)];
        int y = Map[hash(t)];

        cout << dinic(x, y) << endl;
    }

    return 0;
}
 