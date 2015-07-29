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

int a[10000];
bool used[10000];
int cnt;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt += (a[i] == -1);
		used[a[i]] = true;
	}

	if (cnt == 0) {
		cout << 0;
		return 0;
	}

	ll res = 1;

	for (int i = 1; i <= n; i++) {
	 	if (a[i] == -1) {
	 		if (used[i]) {
	 			res *= cnt;
	 			res %= MOD;
	 		} else {
	 			res *= cnt - 1;
	 			res %= MOD;
	 		}
	 	}
	}

	cout << res;
	
	return 0;
}
