#include <iostream>
#include <cstdio>

using namespace std;

const int MAXM = 10010;
const int MAXN = 2010;
const long long INF = (long long)1e18;

int n, m;
long long dist[MAXN];
int from[MAXM], to[MAXM], cost[MAXM];
bool uEdge1[MAXM], uEdgen[MAXM];
bool uVert1[MAXN], uVertn[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &from[i], &to[i], &cost[i]);
        cost[i] *= -1;
    }

    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[1] = 0;                   
    
    uVert1[1] = true;
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < m; i++) {
            if (dist[from[i]] == INF)
                continue;

            if (dist[to[i]] > dist[from[i]] + cost[i]) {
                if (uVert1[from[i]]) {
                    uEdge1[i] = true;
                    uVert1[to[i]] = true;
                }

                dist[to[i]] = dist[from[i]] + cost[i];
            }
        }
    }

    if (dist[n] == INF) {
        puts(":(");
        return 0;
    }

    uVertn[n] = true;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < m; i++) {
            if (dist[from[i]] == INF)
                continue;

            if (dist[to[i]] > dist[from[i]] + cost[i]) {
                if (uVertn[to[i]]) {
                    uEdgen[i] = true;
                    uVertn[from[i]] = true;
                }

                dist[to[i]] = dist[from[i]] + cost[i];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (uEdge1[i] && uEdgen[i]) {
            puts(":)");
            return 0;
        }

        cerr << uEdge1[i] << ' ' << uEdgen[i] << endl;
    }

    printf("%I64d\n", -dist[n]);

    return 0;
}
