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

int color[maxn], sz[maxn], gl[maxn], sm[maxn];
double ans = 0;

void dfs(int v, ll sum, int d = 0) {
	color[v] = 1;
	gl[v] = d;
	sum += sz[v];
	sm[v] = sum;

	for (int i = 0; i < 26 * 26 + 26; i++) {
		int to = to;
		if (color[to] == 1) {
			ans = max(ans, (sum - sm[to] + sz[to] + .0) / (d - gl[to] + .0));
		} 
		if (color[to] == 0)
			dfs(to, sum, d + 1);
	}
	color[v] = 2;
}

int a[26 * 26 + 26][26 * 26 + 26];

vector <vector <int> > g[maxn];
vector <vector <int> > rib[26 * 26 + 26];
bool used[26 * 26 + 26];

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif
	
	ios_base :: sync_with_stdio(false);

	int n;

	string s;

	while ((cin >> n) && n) {
		memset(a, 0, sizeof a);
		ans = 0;
		for (int i = 0; i < maxn; i++) {
			color[i] = 0;
			sz[i] = 0;
			gl[i] = 0;
			sm[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> s;
			int len = s.size();
			if (len < 2)
				continue;

			int c1 = (s[0] - 'a') * 26 + s[1] - 'a';
			int c2 = (s[len - 2] - 'a') * 26 + s[len - 1] - 'a';

			a[c1][c2] = max(a[c1][c2], len);
		}
		for (int i = 0; i < 26 * 26 + 26; i++)
			if (!used[i])
				dfs(i, 0);

		 cout << ans << endl;


	}

	
	return 0;
}
