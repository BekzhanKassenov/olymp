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

const int maxn = 1000010;
int deg[maxn], n, k, x, y;
set <int> g[maxn];
bool used[maxn];

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &x, &y);
		g[--x].insert(--y);
		g[y].insert(x);
		deg[x]++, deg[y]++;
	}

	set <int> leaf;

	for (int i = 0; i < n; i++) {
		if (deg[i] == 1)
			leaf.insert(i);
	}

	int ans = 0;
	stringstream ss;

	while (k > 0) {
		if (k == 1) {
			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					ans++;
					ss << i + 1 << ' ';
					break;
				}
			}
			break;
		}

		set <int> tmp;

		for (set <int> :: iterator it = leaf.begin(); it != leaf.end(); it++) {
			if (used[*it])
				continue;

			used[*it] = true;
			ss << (*it) + 1 << ' ';

			int pr = *g[*it].begin();
			
			g[pr].erase(*it);
			deg[*it]--, deg[pr]--;
			if (deg[pr] == 1)
				tmp.insert(pr);
			ans++;
		}

		leaf = tmp;
		k -= 2;
	}

	printf("%d\n%s", ans, ss.str().c_str());

	return 0;
}
