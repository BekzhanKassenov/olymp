#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 5 * 100010;

struct Edge {
    int cap, flow;
    int to;

    void init(int t, int c, int f) {
        to = t;
        cap = c;
        flow = f;
    }
};

Edge e[4 * MAXN];
int lastEdge;
vector <int> g[MAXN];
map <string, int> num;
string s, t;
int n, m, k;
int parent[MAXN], size[MAXN];
int curFlow;

int get_parent(int a) {
    if (parent[a] == a)
        return a;

    return parent[a] = get_parent(parent[a]);
}

void unite(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b)
        return;

    if (size[a] < size[b]) {
        parent[a] = b;
        size[b] += size[a];
    } else {
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> s >> t;

        if (Map.find(s) == Map.end()) {
            int sz = Map.size();
            Map[s] = sz;
        }

        if (Map.find(t) == Map.end()) {
            int sz = Map.size();
            Map[t] = sz;
        }

        int x = Map[s];
        int y = Map[t];

        unite(x, y);

        for (int j = 0; j < 2; j++) {
            e[lastEdge].init(y, 1, 0);
            g[x].push_back(lastEdge);
            lastEdge++;

            e[lastEdge].init(x, 1, 1);
            g[y].push_back(lastEdge);
            lastEdge++;

            swap(x, y);
        }
    }

    return 0;
}
