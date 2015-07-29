/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "grant"

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
const int maxn = 500010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

vector <int> child[maxn];
int dp[maxn][2], n, x, nxt[maxn];
bool used[maxn];

void dfs(int v) {
	if (child[v].empty())
		return;

	for (size_t i = 0; i < child[v].size(); i++) {
		dfs(child[v][i]);
	}

	int sum = 0;

	for (size_t i = 0; i < child[v].size(); i++)
		sum += dp[child[v][i]][0];

   	dp[v][1] = sum;

   	for (size_t i = 0; i < child[v].size(); i++) {
   		sum -= dp[child[v][i]][0];
   		sum += dp[child[v][i]][1] + 1;
   		
   		if (dp[v][0] < sum) {
   			dp[v][0] = sum;
   			nxt[v] = child[v][i];
   		}

   		sum += dp[child[v][i]][0];
   		sum -= dp[child[v][i]][1] + 1;
   	}
}

void dfs1(int v, bool take) {
	if (take) {
		used[v] = true;

		for (size_t i = 0; i < child[v].size(); i++)
			dfs1(child[v][i], false);
	} else {
		for (size_t i = 0; i < child[v].size(); i++)
			if (child[v][i] == nxt[v])
				dfs1(child[v][i], true);
			else
				dfs1(child[v][i], false);
	}
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &x);
		child[--x].push_back(i + 1);
	}

	dfs(0);

	cout << max(dp[0][1], dp[0][0]) * 1000 << endl;

	if (dp[0][1] > dp[0][0])
		dfs1(0, true);
	else
		dfs1(0, false);	

	for (int i = 1; i < n; i++)
		if (used[i])
			cout << i + 1 << ' ';

	cout << endl;

	return 0;
}

