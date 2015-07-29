/****************************************
**          Solution by NU #2          **
****************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define cost first
#define to second
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "secure"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2000 * 1000 * 1000ll * 10000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 5010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, m, a[maxn], s, t, c, pp[maxn];
ll dist[maxn];
vector <pair <int, int> > g[maxn];
priority_queue <pair <ll, int> > q;
ll ansd = INF, ans1 = 0, ans2 = 0;

void deijkstra(int st) {
	for (int i = 0; i <= n; i++)
		dist[i] = INF, pp[i] = -1;

	dist[st] = 0;
	pp[st] = -1;

	q.push(MP(0, st));

	while (!q.empty()) {
		int v = q.top().S;
		ll d = -q.top().F;
		q.pop();

		if (dist[v] != d)
			continue;

		for (size_t i = 0; i < g[v].size(); i++) {
			if (dist[g[v][i].to] > d + g[v][i].cost) {
				dist[g[v][i].to] = d + g[v][i].cost;
				            
				if (a[v] == 1)
					pp[g[v][i].to] = v;
				else
					pp[g[v][i].to] = pp[v];
						
			//	cerr << v << "->" << g[v][i].to << endl;

				q.push(MP(-dist[g[v][i].to], g[v][i].to));
			}
		}
	}
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	cin >> n >> m;

	vector <int> start, end;

	for (int i = 0; i < n; i++) {
		cin >> a[i];

		if (a[i] == 1)
			start.push_back(i);
		else if (a[i] == 2)
			end.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> s >> t >> c;

		//if (a[--s] == a[--t] && a[s])
		//	continue;

		g[--s].push_back(MP(c, --t));
		g[t].push_back(MP(c, s));
	}

	for (size_t i = 0; i < start.size(); i++) {
		g[start[i]].push_back(MP(1, n));
		g[n].push_back(MP(1, start[i]));
	}

	deijkstra(n);

	ans1 = end[0];

	for (size_t i = 1; i < end.size(); i++)
		if (dist[end[i]] < dist[ans1])
			ans1 = end[i];

	if (dist[ans1] == INF)
		cout << -1;
	else
		cout << pp[ans1] + 1 << ' ' << ans1 + 1 << ' ' << dist[ans1] - 1 << endl;	

	return 0;
}

