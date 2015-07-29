/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int fact(int n) {
 	if (n == 0)
 		return 1;

 	return fact(n - 1) * n;	
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
	
	int n;
	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++) {
	 	cin >> a[i];
	}
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int cnt = a[i];
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				cnt--;

		ans += cnt * fact(n - i - 1);
	}

	cout << ans << endl;

    return 0;
}
