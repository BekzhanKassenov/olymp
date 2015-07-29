/****************************************
**          Solution by NU #2          **
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
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int to, len;
    int insun, outsun;
};

int n, m, t, a, b;
vector <pair <int, int> > g[MAXN];
pair <int, int> temp[200010];
pair <int, int> temp1[200010];
int last;
int x, y, k;
int dist[MAXN];
bool black[MAXN];

Edge e[200010];
int lastEdge;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d%d%d%d", &n, &m, &t, &a, &b);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &k);
        for (int j = 0; j < k; j++)
            scanf("%d%d", &temp[i].first, &temp[i].second);

        last = 0;
        for (int j = 0; j < k; j++) {
            if (last == 0 || temp[j].second != temp1[last - 1].second)
                temp1[last++] = temp[j];
            else
                temp1[last - 1].first += temp[j].first;
        }

        bool ok = true;
        int sum = 0;
        for (int j = 0; j < last; j++) {
            sum += temp1[j].first;
            if (temp1[j].first > t && temp[j].second == 1)
                ok = false;
        }

        if (ok) {
            e[lastEdge].to = y;
            e[lastEdge].len = sum;
            e[lastEdge + 1].to = x;
            e[lastEdge + 1].len = sum;

            if (temp[last - 1].second == 1) {
                e[lastEdge].insun = temp[last - 1].first;
                e[lastEdge + 1].outsun = temp[last - 1].first;
            }

            if (temp[0].second == 1) {
                e[lastEdge].outsun = temp[0].first;
                e[lastEdge + 1].insun = temp[1].
            }
        }

        if (temp1[0].second == 0)
            black[x] = true;

        if (temp1[last - 1].second == 0)
            black[y] = true;
    }

    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
    q.push(make_pair(0, a));

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[a] = 0;

    while (!q.empty()) {
        int v = q.top().second;
        int d = q.top().first;
        q.pop();

        if (d != dist[v])
            continue;

        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i].first;
            int cost = g[v][i].second;

            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                q.push(make_pair(dist[to], to));
            }
        }
    }

    if (dist[b] != INF)
        printf("%d\n", dist[b]);
    else
        puts("-1"); 

    return 0;
}
