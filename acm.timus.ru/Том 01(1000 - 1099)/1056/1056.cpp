#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 10010;

int n, x, ans;
vector <int> g[maxn];
int dist[maxn];
vector <int> res;

struct que {
    int head, tail;
    int arr[maxn];

    void clear() {
        head = tail = 0;
    }

    void push(int val) {
        arr[tail++] = val;
    }

    bool empty() {
        return head >= tail;
    }

    int front() {
        return arr[head];
    }

    void pop() {
        head++;
    }
};

que q;

int bfs(int v) {
    q.clear();
    q.push(v);
    memset(dist, 255, sizeof dist);
    int last = v;
    dist[v] = 0;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (size_t i = 0; i < g[v].size(); i++) {
            if (dist[g[v][i]] == -1) {
                dist[g[v][i]] = dist[v] + 1;
                q.push(g[v][i]);
                last = g[v][i];
            }
        }
    }

    return dist[last];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        x--;

        g[x].push_back(i);
        g[i].push_back(x);
    }

    ans = n;

    for (int i = 0; i < n; i++) {
        int dst = bfs(i);

        if (dst < ans) {
            res.clear();
            res.push_back(i);
            ans = dst;
        } else if (dst == ans) {
            res.push_back(i);
        }
    }

    for (size_t i = 0; i < res.size(); i++)
        printf("%d ", res[i] + 1);
    
    return 0;
}
