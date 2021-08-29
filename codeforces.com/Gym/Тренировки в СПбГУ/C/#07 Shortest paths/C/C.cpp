#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
 
using namespace std;
 
#define PII pair <int, int>
#define MP make_pair
#define F first
#define S second
 
const int maxn = 2010;
const int maxe = 10010;
const long long INF = 1e18;
 
struct Edge {
    int f, t, cost;
};
 
vector <Edge> edge;
int x, y, cost;
long long dist[maxn];
 
int main() {
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
 
	int n, m;
 
	scanf("%d%d", &n, &m);
 
	for (int i = 0; i < m; i++) {
        int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
        edge.push_back({x - 1, y - 1, -c});
	}
 
	for (int i = 0; i < n; i++)
		dist[i] = INF;
 
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (const Edge& e : edge) {
            if (dist[e.t] > dist[e.f] + e.cost && dist[e.f] < INF) {
                dist[e.t] = dist[e.f] + e.cost;
            }
        }
    }

    /*
    for (int i = 0; i < n - 1; i++) {
        cout << dist[i] << ' ';
    }
    cout << endl;
    */

    if (dist[n - 1] == INF) {
        cout << ":(" << endl;
        return 0;
    }
    double oldDist = dist[n - 1];
    for (int i = 0; i < n; i++) {
        for (const Edge& e : edge) {
            if (dist[e.t] > dist[e.f] + e.cost && dist[e.f] != INF) {
                dist[e.t] = -INF;
            }
        }
    }
 
    if (dist[n - 1] < oldDist) {
        cout << ":)" << endl;
    } else {
        cout << -dist[n - 1] << endl;
    }
 
    return 0;
}