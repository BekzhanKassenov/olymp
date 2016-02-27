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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int N, M, A, B, C;
int minA = INF, minB = INF, minC = INF;
int grade[MAXN];
vector <int> g[MAXN];
map <int, pair <int, int> > d1, d2, d3;

void dijkstra(map <int, pair <int, int> >& dist, int start) {
    struct State {
        int node, dist, id;
        bool operator < (const State& s) const {
            if (dist != s.dist) {
                return dist < s.dist;
            }

            if (id < s.id) {
                return id < s.id;
            }

            return node < s.node;
        }
    };

    set <State> Set;
    Set.insert({start, 0, start});
    dist[start] = {0, start};

    while (!Set.empty()) {
        int v = Set.begin()->node;
        int d = Set.begin()->dist;
        int id = Set.begin()->id;

        Set.erase(Set.begin());

        for (int to: g[v]) {
            if (!dist.count(to) || d + 1 < dist[to].first || (d + 1 == dist[to].first && id < dist[to].second)) {
                Set.erase({to, dist[to].first, dist[to].second});
                dist[to] = make_pair(d + 1, min(id, to));
                Set.insert({to, d + 1, min(id, to)});
            }
        }
    }
}

int get(int x) {
    switch (grade[x]) {
        case 1:
            x = minA;
            break;

        case 2:
            x = minB;
            break;

        case 3:
            x = minC;
            break;

        default:
            break;
    }

    return x;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &N, &A, &B, &C);
    
    for (int i = 0; i < A; i++) {
        int x;
        scanf("%d", &x);
        grade[x] = 1;
        minA = min(minA, x);
    }

    for (int i = 0; i < B; i++) {
        int x;
        scanf("%d", &x);
        grade[x] = 2;
        minB = min(minB, x);
    }

    for (int i = 0; i < C; i++) {
        int x;
        scanf("%d", &x);
        grade[x] = 3;
        minC = min(minC, x);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        
        x = get(x);
        y = get(y);

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dijkstra(d1, minA);
    dijkstra(d2, minB);
    dijkstra(d3, minC);

    for (int i = 1; i <= N; i++) {
        if (grade[i] != 0) {
            int num = get(i);
            d1[i] = d1[num];
            d2[i] = d2[num];
            d3[i] = d3[num];
        }
    }

    int dist = INF, minid = INF;
    for (int i = 1; i <= N; i++) {
        int d = d1[i].first + d2[i].first + d3[i].first;
        int id = min(min(d1[i].second, d2[i].second), d3[i].second);

        if (d < dist || (d == dist && id < minid)) {
            dist = d;
            minid = id;
        }
    }

    printf("%d %d\n", dist, minid);

    return 0;
}
