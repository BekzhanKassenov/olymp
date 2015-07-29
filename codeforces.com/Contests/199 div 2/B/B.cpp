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

	int n, m, s, f;

	cin >> n >> m >> s >> f;

	int add = 1;
	char c = 'R';

	if (s > f) {
		add = -1;
		c = 'L';
	}	

	int t, l, r;
	int tim = 1;
	string res;
	bool found = false;

	for (int i = 0; i < m && !found; i++) {
		cin >> t >> l >> r;

		while (tim < t && !found) {
			res += c;
			s += add;
			tim++;

			if (s == f)
				found = true;
		}

		if (!found) {
		if (((s >= l && s <= r) || (s + add >= l && s + add <= r))) 
			res += 'X';
		else {
			res += c;
			s += add;
			if (s == f)
				found = true;
		}
		}
		tim++; 
	}

	if (!found) {
		while (s != f) {
			s += add;
			res += c;
		}
	}

	cout << res;

	return 0;
}
