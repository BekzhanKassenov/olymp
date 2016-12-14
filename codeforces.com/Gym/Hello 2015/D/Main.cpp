/****************************************
**     Solution by Bekzhan Kassenov    **
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
const long long INF = 2000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int to;
    long long w;
    int c;
};

struct State {
    long long dist;
    int c;

    State() : dist(-1), c(-1) {}

    State(long long dist, int c) : dist(dist), c(c) {}

    bool operator < (const State& other) const {
        if (empty() || other.empty()) {
            return false;
        }
        return dist < other.dist || (dist == other.dist && c < other.c);
    }

    bool empty() const {
        return dist == -1;
    }

    bool operator == (const State& other) const {
        return dist == other.dist && c == other.c;
    }

    bool operator != (const State& other) const {
        return dist != other.dist || c != other.c;
    }
};

ostream& operator << (ostream& out, const State& s) {
    return out << s.dist << ' ' << s.c;
}

int n, m, C;
Edge e[MAXN];
State state1[MAXN], state2[MAXN];
vector <int> g[MAXN];

State update(long long d, int v, int c) {
    State &s1 = state1[v];
    State &s2 = state2[v];
    State s(d, c);

    #define update_existing(x) \
        if (!x.empty() && x.c == c) { \
            if (x.dist > d) { \
                x = s; \
                if (s2 < s1) { \
                    swap(s2, s1); \
                } \
                return s; \
            } \
            return State(); \
        } \

    update_existing(s1);
    update_existing(s2);

    #define update_empty(x) \
        if (x.empty()) { \
            x = s;\
            if (s2 < s1) { \
                swap(s2, s1); \
            } \
            return s; \
        } \
        
    update_empty(s1);
    update_empty(s2);

    if (d < s1.dist) {
        s2 = s1;
        s1 = s;
        return s;
    }

    if (d < s2.dist) {
        s2 = s;
        return s;
    }

    return State();
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &C);
                        
    for (int i = 0; i < m; i++) {
        int from;
        scanf("%d%d%lld%d", &from, &e[i].to, &e[i].w, &e[i].c);
        g[from].push_back(i);
    }

    int s, Q;
    scanf("%d%d", &s, &Q);
    
    priority_queue <pair <State, int>,
                    vector <pair <State, int> >,
                    greater <pair <State, int> > > q;

    state1[s] = {0, 0};
    q.emplace(state1[s], s);

    while (!q.empty()) {
        int v = q.top().second;
        State s = q.top().first;

        q.pop();

        if (state1[v] != s && state2[v] != s) {
            continue;
        }

        for (int idx : g[v]) {
            if (s.c == e[idx].c) {
                continue;
            }

            int to = e[idx].to;
            State ns = update(s.dist + e[idx].w, to, e[idx].c);
            if (!ns.empty()) {
                q.emplace(ns, to);
            }
        }
    }

    while (Q--) {
        int t;
        scanf("%d", &t);
        printf("%lld\n", state1[t].dist);
    }

    return 0;
}
