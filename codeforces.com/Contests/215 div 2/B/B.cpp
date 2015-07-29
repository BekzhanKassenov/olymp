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
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int ans[100010];

bool used[100010];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	VI a(n);

	for (int i = 0; i < n; i++) {
		 cin >> a[i];
	}

	int sz = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (!used[a[i]]) {
			sz++;
			used[a[i]] = true;
		}

		ans[i] = sz;
	}

	for (int i = 0; i < m; i++) {
		int l;

		cin >> l;

		cout << ans[l - 1] << endl;
	}


	return 0;
}
