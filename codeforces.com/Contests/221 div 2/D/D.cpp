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

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int maxn = 5010;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int a[maxn][maxn], sum[maxn][maxn], cnt[maxn], n, m;
char c;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;

			a[i][j] = c - '0';
		}
	}


	for (int i = 0; i < n; i++) {
		sum[i][0] = a[i][0];

		for (int j = 1; j < m; j++) {
			if (a[i][j] == 0)
				sum[i][j] = 0;
			else
				sum[i][j] = sum[i][j - 1] + 1;	
		}
	}

	int ans = 0;

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			cnt[sum[i][j]]++;
		}

		int cur = n;

		for (int i = 0; i <= m; i++) {
			if (cnt[i] > 0) {
				ans = max(ans, cur * i);    
				cur -= cnt[i];
			}
		}

		for (int i = 0; i < n; i++)
			cnt[sum[i][j]]--;
	}

	cout << ans;

	return 0;
}
