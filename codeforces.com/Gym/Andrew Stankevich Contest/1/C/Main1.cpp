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

int n, par[maxn], deg[maxn];
bool used[maxn];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &par[i]);
		par[i]--;
		deg[par[i]]++;
	}

	queue <int> q;

	for (int i = 0; i < n; i++)
		if (deg[i] < 1)
			q.push(i);

	vector <int> ans;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (v != 0 && !used[v] && !used[par[v]]) {
			cout << v + 1 << endl;
			used[v] = used[par[v]] = true;
			ans.push_back(v);
			q.push(par[par[v]]);
	   	}
	}

	cout << ans.size() * 1000 << endl;

	sort(all(ans));

	for (size_t i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << ' ' ;

	return 0;
}

