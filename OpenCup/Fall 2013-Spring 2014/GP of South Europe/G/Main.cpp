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
#define File "g"
#define maxn 1000010

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

int a[maxn], b[maxn], c[maxn], dp[maxn][2][2], n;

int main() {
	freopen(File".in", "r", stdin);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];


	if (n == 1) {
		cout << a[1];
		return 0;
	}

	dp[1][0][0] = 0;
	dp[1][1][0] = a[1];
	dp[1][0][1] = 0;
	dp[1][1][1] = a[1];
	dp[2][0][0] = 0;
	dp[2][1][0] = a[2];
	dp[2][0][1] = a[1];
	dp[2][1][1] = b[1] + b[2];

	//cout << " dp[i][0][0]  dp[i][1][0]  dp[i][0][1]  dp[i][1][1]\n";

	for (int i = 3; i <= n; i++) {
		dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1]);
		dp[i][0][1] = max(dp[i - 1][1][0], dp[i - 1][1][1]);
		dp[i][1][0] = max(dp[i - 1][0][0], dp[i - 1][0][1]) + a[i];
		
		dp[i][1][1] = max(dp[i - 1][1][1] + c[i - 1] - b[i - 1], dp[i - 1][1][0] + b[i - 1] - a[i - 1]) + b[i];

	//	cout << dp[i][0][0] << ' ' << dp[i][1][0] << ' ' << dp[i][0][1] << ' ' << dp[i][1][1] << endl;
	}

	int ans = 0;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ans = max(ans, dp[n][i][j]);

	cout << ans;	

	return 0;
}
