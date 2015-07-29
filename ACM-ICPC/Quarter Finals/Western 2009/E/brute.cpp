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

pair <bool, int> extremal(const vector <int>& a) {
	if (a.size() <= 2)
		return MP(false, 0);

	if (!((a[1] > a[0] && a[1] > a[2]) || (a[1] < a[0] && a[1] < a[2])))
		return MP(false, -1);

	int type = (a[1] > a[0] && a[1] > a[2]);

	int k = type;

	for (int i = 2; i < (int)a.size() - 1; i++) {
		if (!((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])))
			return MP(false, 0);

		int type1 = (a[i] > a[i - 1] && a[i] > a[i + 1]);

		if (type1 == type)
			return MP(false, 0);

		type = type1;
	}

	return MP(true, k);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	for (int n = 1; n <= 11; n++) {
		vector <int> a(n);

		for (int i = 0; i < n; i++)
			a[i] = i;

		int res1 = 0, res2;

		do {
		 	 pair <bool, int> t = extremal(a);

		 	 if (!t.F)
		 	 	continue;

		 	 if (t.S)
		 	 	res1++;
		 	 else
		 	 	res2++;
		} while (next_permutation(all(a)));

		cout << res1 << ' ';
		res1 = res2 = 0;
	}

	return 0;
}
