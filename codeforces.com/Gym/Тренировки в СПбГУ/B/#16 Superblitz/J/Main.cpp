#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXM = 10010;
const int MAXN = 2010;
const long long INF = (long long)1e16;
 
int n, m;
long long dist[MAXN], tdist[MAXN];
int from[MAXM], to[MAXM], cost[MAXM];
bool used[MAXN], used1[MAXN];
 
void bfs() {
    queue <int> q;
    q.push(1);
    used[1] = true;
 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
 
        for (int i = 0; i < m; i++) {
            if (from[i] == v && !used[to[i]]) {
                used[to[i]] = true;
                q.push(to[i]);
            }
        }
    }
}
 
void bfs1() {
    queue <int> q;
    q.push(n);
    used[n] = true;
 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
 
        for (int i = 0; i < m; i++) {
            if (to[i] == v && !used1[from[i]]) {
                used1[from[i]] = true;
                q.push(from[i]);
            }
        }
    }
}
 
 
void iterate(long long dist[]) {
    for (int i = 0; i < m; i++) {
        if (dist[from[i]] == INF)
            continue;
 
        if (dist[to[i]] > dist[from[i]] + cost[i]) {
            dist[to[i]] = max(-INF, dist[from[i]] + cost[i]);
        }
    }
}
 
int main() {
    scanf("%d%d", &n, &m);
 
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &from[i], &to[i], &cost[i]);
        cost[i] *= -1;
    }
 
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[1] = 0;                   
 
    for (int i = 0; i < n - 1; i++)
        iterate(dist);
 
    memcpy(tdist, dist, sizeof tdist);
    iterate(tdist);
     
    bfs();
    bfs1();
 
    for (int i = 1; i <= n; i++) {
        if (dist[i] != tdist[i] && used[i] && used1[i]) {
            puts(":)");
            return 0;
        }
    }
 
    if (dist[n] == INF) {
        puts(":(");
        return 0;
    }
 
    printf("%I64d\n", -dist[n]);
 
    return 0;
}