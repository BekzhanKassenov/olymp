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

	int n;
	
	cin >> n;

	int a;

	cin >> a;

	int x;

	int res = 1;

	for (int i = 1; i < n; i++) {
		cin >> x;

		if (x == 10) {
			if (a == 1)
				res++;
		} else {
			if (a == 10)
				res++;
		}
		a = x;
   	}

   	cout << res;

	return 0;
}
