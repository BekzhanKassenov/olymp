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
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd
#define File "wires"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int a[100][100];
bool red[100], used[100];
int n;

void dfs(int v, vector <int>& comp, bool& has_red) {
 	used[v] = true;
 	if (red[v])
 		has_red = true;
	comp.push_back(v);

	for (int i = 0; i < n; i++)
		if (a[v][i] && !used[i])
			dfs(i, comp, has_red);	
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	cin >> n;

	char c;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> c;
			a[i][j] = (c == '1');
		}

	int m;

	cin >> m;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		red[x] = true;
	}

	int mult = 0;
	int ma = 0;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			bool has_red = false;
			vector <int> comp;
			dfs(i, comp, has_red);

			int sz = comp.size();
			int cnt = 0;

			for (int i = 0; i < sz; i++) 
				for (int j = 0; j < i; j++)
					if (a[comp[i]][comp[j]])
						cnt++;

			ans += (sz * (sz - 1)) / 2 - cnt;

			if (has_red)
				ma = max(ma, sz);
			else {
				ans += mult * sz;
				mult += sz;
			}
		}
	}

	ans += ma * mult;

	cout << ans;

	return 0;
}
