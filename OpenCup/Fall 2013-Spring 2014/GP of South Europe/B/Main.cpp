/****************************************
**         Solution by NU_02           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal
#define File "b"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2000ll * 1000 * 1000 * 1000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

const int maxn = 3e6;

vector <int> g[maxn];
ll dist[maxn];
int a, b, n, k;
bool flag;

struct que {
 	int a[maxn];
 	int head, tail;
 	que() : head(0), tail(0) {}

 	void push(int n) {
 		a[tail++] = n;
 	}

 	void pop() {
 		head++;
 	}

 	int front() {
 		return a[head];
 	}

 	bool empty() {
 		return (head >= tail);
 	}

 	void clear() {
 		head = tail = 0;
 	}
};

que q;
bool inque[maxn];

void bfs() {
	q.clear();
	q.push(1);
	inque[1] = true;

	dist[n] = b;

	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	memset(inque, 0, sizeof inque);
	dist[1] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		inque[v] = false;

		for (size_t i = 0; i < g[v].size(); i++) {
			int to = g[v][i];
			if (dist[to] > dist[v] + a) {
				dist[to] = dist[v] + a;
				if (!inque[to] && dist[to] < dist[n])
					q.push(to);
				inque[to] = true;
			}
		}
	}
}

void bfs1() {
	q.clear();
	q.push(1);
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	memset(inque, 0, sizeof inque);
	dist[n] = a;
	dist[1] = 0;
	inque[1] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		inque[v] = false;
		int pos = 0;
		int len = g[v].size();

		for (int i = 1; i <= n; i++) {
			if (pos < len && i == g[v][pos]) {
				pos++;
				continue;
			}
				
			if (dist[i] > dist[v] + b) {
				dist[i] = dist[v] + b;

				if (dist[i] < dist[n] && !inque[i]) 
					q.push(i);
			}
		}
	}
}

/*void dfs(int v) {
	int pos = g[v].size() - 1;

	for (int i = n; i >= 1; i++) {
	 	if (pos >= 0 && i == g[v][pos]) {
	 		pos--;
	 		continue;
	 	}

	 	if (dist[i] > dist[v] + b) {
	 		dist[i] = dist[v] + b;
	 		if (dist[i] < dist[n])
	 			dfs(i);
	 	}
	}
}*/

int main() {
	freopen(File".in", "r", stdin);

	scanf("%d%d%d%d", &n, &k, &a, &b);

	int x, y;

	for (int i = 0; i < k; i++) {
	   	scanf("%d%d", &x, &y);

	   	if ((x == 1 && y == n) || (x == n && y == 1))
	   		flag = true;

	   	g[x].push_back(y);
	   	g[y].push_back(x);
	}

	for (int i = 0; i < n; i++)
		sort(all(g[i]));

	if (flag) {
		if (a <= b) 
			cout << a;
		else {
			/*for (int i = 1; i <= n; i++)
				dist[i] = INF;
			
			dist[1] = 0;

			dfs(1);*/

			bfs1();

			cout << min(dist[n], a * 1ll);
		}	
	} else {
		if (b <= a) 
			cout << b;
		else {
			bfs();
			cout << min(dist[n], b * 1ll);
		}
	}

	return 0;
}
