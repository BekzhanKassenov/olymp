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
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

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

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	VI a(n);

	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	string s;
	cin >> s;
	reverse(all(s));
	reverse(all(a));
	bool flag = true;

	for (int i = 0; i < n && flag; i++) {
		if (s[i] == '0') 
		 	flag = false;
	}

	if (flag) {
	  	cout << sum;
	  	return 0;
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
		if (s[i] == '1')
			ans += a[i];

	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			sum -= a[i];
		else 
			ans = max(ans, sum - a[i]);
	}

	cout << ans;

	return 0;
}
