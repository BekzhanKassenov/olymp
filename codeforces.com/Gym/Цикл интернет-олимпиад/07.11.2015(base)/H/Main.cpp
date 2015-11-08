/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "streets"

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

int n, m, k;
vector <pair <int, int> > g[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
int S, T, N;
bool inque[MAXN];
int dist[MAXN];

int bfs01(int S, int T) {
    deque <int> q;
    q.push_back(S);
    memset(dist, 255, sizeof dist);
    dist[S] = 0;
    inque[S] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        inque[v] = false;

        for (auto edge: g[v]) {
            int to = edge.first;
            int weight = edge.second;

            if (dist[to] == -1) {
                q.push_back(to);
                dist[to] = dist[v] + weight;
                inque[to] = true;
            } else if (dist[to] > dist[v] + weight) {
                dist[to] = dist[v] + weight;

                if (!inque[to]) {
                    q.push_front(to);
                    inque[to] = true;
                }
            }
        }
    }

    return dist[T];
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
    }

    scanf("%d", &T);
    S = 0;
    N = max(max(max(*max_element(a, a + n), *max_element(b, b + m)), *max_element(c, c + k)), T) + 2;
    T += N;

    sort(a, a + n);
    sort(b, b + m);
    sort(c, c + k);

    for (int i = 0; i + 1 < N; i++) {
        int weightA = binary_search(a, a + n, i);
        g[i].emplace_back(i + 1, weightA);
        g[i + 1].emplace_back(i, weightA);

        int weightB = binary_search(b, b + m, i);
        g[N + i].emplace_back(N + i + 1, weightB);
        g[N + i + 1].emplace_back(N + i, weightB);

        if (binary_search(c, c + k, i)) {
            g[i].emplace_back(N + i, 1);
            g[N + i].emplace_back(i, 1);
        }
    }

    printf("%d\n", bfs01(S, T));


    /*for (int i = 0; i < 2 * N; i++) {
        cerr << i % N << ' ' << dist[i] << endl;
    }
     */
    return 0;
}