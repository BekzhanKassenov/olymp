/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "problem"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 310;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int x[MAXN], y[MAXN];
bool used[MAXN];
int ans = INF;

int dist(int a, int b) {
 	return sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
}

int dfs(int v) {
 	used[v] = true;

	int pos = -1;

	for (int i = 0; i < n; i++) {
	 	if (!used[i] && (pos == -1 || dist(v, i) < dist(v, pos)))
	 		pos = i;
	}

	if (pos == -1)
		return 0;

	return dist(v, pos) + dfs(pos);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
     	scanf("%d%d", &x[i], &y[i]);
    }

    for (int i = 0; i < n; i++) {
		ans = min(ans, dfs(i));
		memset(used, 0, sizeof used);
    }

    printf("%d\n", ans);
    
    return 0;
}
