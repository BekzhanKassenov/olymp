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
const int MAXN = 500;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct rib {
	int b, u, c, f;
	size_t back;

    bool operator == (const rib& r) const {
        return b == r.b && u == r.u && c == r.c; //&& back == r.back;
    }
};

vector <rib> g[MAXN];
int n, k;
int s, t;
int x;
int aa[MAXN], bb[MAXN];

void add_rib (int a, int b, int u, int c) {
	rib r1 = { b, u, c, 0, g[b].size() };
	rib r2 = { a, 0, -c, 0, g[a].size() };
	g[a].push_back (r1);
	g[b].push_back (r2);
}

void remove_rib (int a, int b, int u, int c) {
	rib r1 = { b, u, c, 0, g[b].size() };
	rib r2 = { a, 0, -c, 0, g[a].size() };
	g[a].erase (find(all(g[a]), r1));
	g[b].erase (find(all(g[b]), r2));
}

int get_flow() {
    int flow = 0,  cost = 0;
	while (flow < k) {
        vector<int> id (MAXN, 0);
		vector<int> d (MAXN, INF);
		vector<int> q (MAXN);
		vector<int> p (MAXN);
		vector<size_t> p_rib (MAXN);
		int qh=0, qt=0;
		q[qt++] = s;
		d[s] = 0;
		while (qh != qt) {
			int v = q[qh++];
			id[v] = 2;
			if (qh == n)  qh = 0;
			for (size_t i=0; i<g[v].size(); ++i) {
				rib & r = g[v][i];
				if (r.f < r.u && d[v] + r.c < d[r.b]) {
					d[r.b] = d[v] + r.c;
					if (id[r.b] == 0) {
						q[qt++] = r.b;
						if (qt == n)  qt = 0;
					}
					else if (id[r.b] == 2) {
						if (--qh == -1)  qh = n-1;
						q[qh] = r.b;
					}
					id[r.b] = 1;
					p[r.b] = v;
					p_rib[r.b] = i;
				}
			}
		}
		if (d[t] == INF)  break;
		int addflow = k - flow;
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v];
			addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
		}
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			cost += g[pv][pr].c * addflow;
		}
		flow += addflow;
	}

    return cost;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &k, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &bb[i]);
    }

    s = 0, t = 1;

    add_rib(s, 2, (k + 1) / 2, 0);
    add_rib(s, 3, k / 2, 0);

    for (int i = 0; i < n; i++) {
        add_rib(2, 4 + i, 1, aa[i]);
    }

    for (int i = 0; i < n; i++) {
        add_rib(3, 4 + i, 1, bb[i]);
    }

    for (int i = 0; i < n; i++) {
        add_rib(4 + i, t, 1, 0);
    }

    int ans = get_flow();

    for (int i = 0; i < n + 10; i++) {
        g[i].clear();
    }

    add_rib(s, 2, k / 2, 0);
    add_rib(s, 3, (k + 1) / 2, 0);

    for (int i = 0; i < n; i++) {
        add_rib(2, 4 + i, 1, aa[i]);
    }

    for (int i = 0; i < n; i++) {
        add_rib(3, 4 + i, 1, bb[i]);
    }

    for (int i = 0; i < n; i++) {
        add_rib(4 + i, t, 1, 0);
    }

    ans = min(ans, get_flow());

    printf("%d\n", ans);

    return 0;
}
