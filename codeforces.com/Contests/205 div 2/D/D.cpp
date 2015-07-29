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

	ios_base :: sync_with_stdio(false);

	string s;
	getline(cin, s);

	int n = s.size();

	bool flag = true;

	int cnt = -1, ans = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] != s[0])
			flag = false;

		if (s[i] == 'M' && cnt == -1)
			cnt = i;
	}	

	if (flag) {
		cout << 0;
		return 0;
	}

	for (int i = cnt; i < n; i++) {
	 	if (s[i] == 'F') {
	 		ans = max(ans + 1, i - cnt);
	 		cnt++;
	 	}
	}

	cout << ans;

	return 0;
}
