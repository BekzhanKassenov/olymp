/****************************************
**         Solution by NU #2           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "max"

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

int a[500][500], dp[500][500], sum[500][500], par[500][500];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)	
			cin >> a[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + a[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			par[i][j] = par[j][i] = 1;
			dp[i][j] = dp[j][i] = sum[j][1] - sum[i - 1][1];
		}

   	int ans = -INF, y1 = -1, y2 = -1, sec = -1, fir = -1;
   	
   	for (int j = 2; j <= m; j++) {
   		for (int i = 1; i <= n; i++) {
   			for (int k = i + 1; k <= n; k++) {
   				if (ans < dp[i][k] + sum[k][j] - sum[i - 1][j]) {
   					ans =  dp[i][k] + sum[k][j] - sum[i - 1][j];
   					y1 = i; y2 = k; sec = j;
   					fir = par[i][k];
   				}

   				if (dp[i][k] + a[i][j] + a[k][j] < sum[k][j] - sum[i - 1][j]){
   					dp[i][k] = dp[k][i] = sum[k][j] - sum[i - 1][j];
   					par[i][k] = par[k][i] = j;
   				} else
   					dp[i][k] = dp[k][i] = dp[i][k] + a[i][j] + a[k][j];
   			}
   		}
   	}

   	cout << ans << endl;
   	
   	cout << min(y1, y2) << ' ' << fir << ' ' << max(y1, y2) << ' ' << sec;
	
	return 0;
}
