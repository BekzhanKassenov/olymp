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

	string s;
	getline(cin, s);

	vector <pair <char, int> > a;

	for (size_t i = 0; i < s.size(); i++) {
		if (a.empty() || a.back().F != s[i])
			a.push_back(MP(s[i], 1));
		else
			a.back().S++;	
	}

	int n = a.size();

	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i].S > 2) {
			ans += a[i].S - 2;
			a[i].S = 2;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		if (a[i].S == 2 && a[i + 1].S == 2) {
			ans++;
			a[i + 1].S = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		while (a[i].S--)
			cout << a[i].F;
	}
	return 0;
}
