/****************************************
**     Solution by Bekzhan Kassenov    **
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

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

const int maxn = 100010;

int t[maxn], a[maxn], deg[maxn], rev[maxn], n;
vector <int> ansv, tmp;

int dfs(int v, int gl = 0) {
	if (deg[v] > 1 || v == 0)
		return gl;

	tmp.push_back(v);

	return dfs(a[v], gl + 1);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) 
		scanf("%d", &t[i]);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);	
		deg[a[i]]++;
	}

	int ans = 0;	

	for (int i = 1; i <= n; i++) {
		if (t[i] == 1) {
			tmp.clear();

			int k = dfs(i);

			if (ans < k) {
				ansv = tmp;
				ans = k;
			}
		}	
	}

	cout << ans << endl;

	reverse(all(ansv));

	for (int i = 0; i < (int)ansv.size(); i++)
		cout << ansv[i] << ' ';

	return 0;
}
