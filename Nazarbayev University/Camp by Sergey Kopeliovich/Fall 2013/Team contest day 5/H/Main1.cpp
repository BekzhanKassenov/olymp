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

int a[400][400], b[400][400];
int dp[400][400];
int sum[400];

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif
	int n, m;
	while (cin >> n >> m && n && m) {
	    memset(a, 0, sizeof a);
	    memset(b, 0, sizeof b);
	    memset(dp, 0, sizeof dp);
	    memset(sum ,0, sizeof sum);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> a[i][j];

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> b[i][j];
	
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				sum[i] += b[i][j];
		}

		for (int j = 0; j <= m; j++)
			dp[0][j] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				sum[i] = sum[i] - b[i][j] + a[i][j];

				for (int prev = 0; prev <= j; prev++)
					dp[i][j] = max(dp[i - 1][prev] + sum[i], dp[i][j]);
			}   	
		}

		/*for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++)
				printf("%6d", dp[i][j]);
			cout << endl;	
		}  */
	
		int ans = 0;

		for (int j = 0; j <= m; j++)
			ans = max(ans, dp[n][j]);

		cout << ans << endl;
	}
		
	return 0;
}
