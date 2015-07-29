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
#define File "i"

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


const int maxn = 6000;

vector <int> g[maxn];
int s[maxn];
bool used[maxn];
int n, k;
int fan[maxn], sz[maxn];

int dfs(int v) {
	if (used[v])	
		return sz[v];
	used[v] = true;

	int cnt = 0;

	for (size_t i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to == v)
			continue;
		cnt += dfs(to);
	}
	sz[v] = cnt + 1;
	return cnt + 1;
}

int main() {
	freopen(File".in", "r", stdin);

	scanf("%d%d", &n, &k);

	for (int i = 0; i < k; i++)
		cin >> fan[i];

	int x;
	char c;

	for (int i = 1; i <= n; i++) {
		while (true) {
			scanf("%d", &x);
			g[i].push_back(x);  		
			c = getchar();
			if (c != ' ')
				break;
		}
		if (c == EOF)
			break;
	}

	/*for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < g[i].size(); j++)
			cout << g[i][j] << ' ' ;
		cout << endl;	
	}*/


	int ans = 0, ans_k = 0;

	for (int i = 0; i < k; i++) {
		int k = dfs(fan[i]);
		if (k > ans) {
			ans = k;
			ans_k = fan[i];
		}
	}

	cout << ans_k;

	return 0;
}
