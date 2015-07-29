/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

const int maxn = 10010;
int timer, tin[maxn], fup[maxn], color[maxn], dist[maxn], n, m, x, y, f, s;
bool used[maxn];
vector <int> g[maxn], g1[maxn];
set <PII> br;

void dfs(int v, int pr = -1) {
 	tin[v] = fup[v] = ++timer;

 	used[v] = true;

 	for (size_t i = 0; i < g[v].size(); i++) {
 		int to = g[v][i];

 		if (pr == to)
 			continue;

 		if (!used[to]) {
 			dfs(to, v);
 			fup[v] = min(fup[v], fup[to]);

 			if (fup[to] > tin[v])
 				br.insert(MP(min(v, to), max(v, to)));
 		} else 
 		 	fup[v] = min(fup[v], tin[to]);
 	}
}

void dfs1(int v, int col) {
	color[v] = col;

	for (size_t i = 0; i < g[v].size(); i++) {
		PII edge = MP(min(v, g[v][i]), max(v, g[v][i]));
		if (!br.count(edge) && !color[g[v][i]])
			dfs1(g[v][i], col);
	}          
}

void build() {
	for (set <PII> :: iterator it = br.begin(); it != br.end(); it++) {
		int cnt = 0;

		for (size_t i = 0; i < g[it -> F].size(); i++) 
			cnt += (g[it -> F][i] == it -> S);
		
		if (cnt == 1) {
			g1[color[it -> F]].push_back(color[it -> S]);
			g1[color[it -> S]].push_back(color[it -> F]);
		}
  	}
}

void dfs2(int v, int gl = 0, int pr = -1) {
	dist[v] = gl;

	for (size_t i = 0; i < g1[v].size(); i++)
		if (g1[v][i] != pr)
			dfs2(g1[v][i], gl + 1, v);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
    	scanf("%d%d", &x, &y);

    	g[--x].push_back(--y);
    	g[y].push_back(x);
    }

    dfs(0);

    int cc = 0;
    
    for (int i = 0; i < n; i++)
    	if (!color[i]) {
    		cc++;
    		dfs1(i, cc);
    	}

   	build();

   	dfs2(1);

   	int tmpd = 0;
   	s = 1;

   	for (int i = 0; i <= n; i++) {
   		if (dist[i] > tmpd) {
   		 	tmpd = dist[i];
   		 	s = i;
   		}
   	}
   	memset(dist, 0, sizeof dist);

   	dfs2(s);
   	tmpd = 0;
   	f = 1;

   	for (int i = 0; i <= n; i++) {
   		if (dist[i] > tmpd) {
   			tmpd = dist[i];
   			f = i;
   		}
   	}

   	for (int i = 0; i < n; i++) {
   		if (color[i] == s) {
   			s = i;
   			break;
   		}
   	}

   	for (int i = 0; i < n; i++) {
   		if (color[i] == f) {
   			f = i;
   			break;
   		}
   	}

   	cout << s + 1 << ' ' << f + 1 << endl;

	return 0;
}
