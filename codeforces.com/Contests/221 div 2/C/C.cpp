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

bool used[10];

int calc_mod(const string& s) {
	int ans = 0;

	for (size_t i = 0; i < s.size(); i++) {
		ans *= 10;
		ans += s[i] - '0';
		ans %= 7;
	}

	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;
	cin >> s;

	string t;

	for (size_t i = 0; i < s.size(); i++) {
		if ((s[i] == '1' || s[i] == '6' || s[i] == '8' || s[i] == '9') && !used[s[i] - '0']) {
			used[s[i] - '0'] = true;
		} else
			t += s[i];
	}

	s = "1689";

	int md = calc_mod(t);

	int md1 = 1;

	for (size_t i = 0; i < t.size(); i++) {
		md1 *= 10;
		md1 %= 7;
	}

	do {
		int a = calc_mod(s) * md1 % 7;

		if (a == (7 - md) % 7) {
			cout << s << t << endl;
			return 0;
		}
			
	} while (next_permutation(all(s)));

	return 0;
}
