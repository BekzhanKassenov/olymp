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
const int MAXN = 20000 + 13;
const int MAXM = 100000 + 13;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct buka {
	int f, t, w;
} a[MAXM];

int n, m, p[MAXN], h[MAXN], ans;

bool cmp (const buka &A, const buka &B) {
	return A.w < B.w;
}

int find_set (int v) {
	if (v == p[v]) 
		return v;
	p[v] = find_set (p[v]);
	return p[v];
}

void union_set (int v, int u) {
	if (h[v] == h[u])
		h[v]++;

	if (h[v] > h[u]) 
		p[u] = v;
	else
		p[v] = u; 	
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
    	cin >> a[i].f >> a[i].t >> a[i].w;
    	a[i].f--, a[i].t--;
    }

    for (int i = 0; i < n; i++)
    	h[i] = 1, p[i] = i;

    sort (a, a + m, cmp);

    for (int i = 0; i < m; i++) {
		int x = find_set (a[i].f);
		int y = find_set (a[i].t);

    	if (x != y) {
    		union_set (x, y);
    		ans += a[i].w;
    	}	
    }

    cout << ans << endl;

    return 0;
}
