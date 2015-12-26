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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int p[MAXN];
int tree_l[MAXN], tree_r[MAXN];

void update(int pos, int tree[], int cnt) {
 	for (int i = pos; i <= n; i |= i + 1) {
 	 	tree[i] += cnt;
 	}
}

int sum(int pos, int tree[]) {
 	int res = 0;
 	for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
		res += tree[i];
 	}

 	return res;
}

int sum(int l, int r, int tree[]) {
	return sum(r, tree) - sum(l - 1, tree);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = 1; i <= n; i++)
		update(p[i], tree_r, 1);
	
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
    	update(p[i], tree_r, -1);

    	ans += 1ll * sum(p[i], n, tree_l) * sum(1, p[i], tree_r);
    	update(p[i], tree_l, 1); 
    }

    cout << ans << endl;
    return 0;
}
