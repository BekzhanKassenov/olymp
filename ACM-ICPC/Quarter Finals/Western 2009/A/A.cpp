/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);
	int n, t;
	cin >> t >> n;

	VI a(3 * n);

	while (t--) {
		for (int i = 0; i < 3 * n; i++)
			cin >> a[i];

		sort(all(a));

		long long ans = 0;

		int ptr = 0;

		long long ans1 = 0;

		for (int i = 3 * n - 1; i >= n; i -= 2) {
			ans += (a[i] - a[ptr]) * a[i - 1];
			ans1 += (a[i - 1] - a[ptr]) * a[i];
			ptr++;
		}

		cout << max(ans, ans1) << endl;
	}
	return 0;
}
